/*
 * Copyright (c) 2010-2012, 2014-2016 ARM Limited
 * Copyright (c) 2013 Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder.  You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Copyright (c) 2004-2006 The Regents of The University of Michigan
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Kevin Lim
 *          Korey Sewell
 */

#ifndef __CPU_O3_RENAME_IMPL_HH__
#define __CPU_O3_RENAME_IMPL_HH__

#include <list>

#include "arch/isa_traits.hh"
#include "arch/registers.hh"
#include "config/the_isa.hh"
#include "cpu/o3/rename.hh"
#include "cpu/reg_class.hh"
#include "debug/Activity.hh"
#include "debug/Rename.hh"
#include "debug/O3PipeView.hh"
#include "params/DerivO3CPU.hh"


//zsx add
//#include "cpu/o3/RegPredictTable.hh"
#include "cpu/o3/regfile.hh"
#include "cpu/o3/PhyRegTable.hh"

using namespace std;

template <class Impl>
DefaultRename<Impl>::DefaultRename(O3CPU *_cpu, DerivO3CPUParams *params)
	: cpu(_cpu),
	iewToRenameDelay(params->iewToRenameDelay),
	decodeToRenameDelay(params->decodeToRenameDelay),
	commitToRenameDelay(params->commitToRenameDelay),
	renameWidth(params->renameWidth),
	commitWidth(params->commitWidth),
	numThreads(params->numThreads)
{
	if (renameWidth > Impl::MaxWidth)
		fatal("renameWidth (%d) is larger than compiled limit (%d),\n"
			"\tincrease MaxWidth in src/cpu/o3/impl.hh\n",
			renameWidth, static_cast<int>(Impl::MaxWidth));

	// @todo: Make into a parameter.
	skidBufferMax = (decodeToRenameDelay + 1) * params->decodeWidth;
}

template <class Impl>
std::string
DefaultRename<Impl>::name() const
{
	//zsx debug

	//printf("cpu name is %s,this function return %s",cpu->name(),cpu->name() + ".rename");

   // cout<< "cpu name is " << cpu->name() << "," << "this function return " << cpu->name() + ".rename" <<endl;

	return cpu->name() + ".rename";
}

template <class Impl>
void
DefaultRename<Impl>::regStats()
{
	renameSquashCycles
		.name(name() + ".SquashCycles")
		.desc("Number of cycles rename is squashing")
		.prereq(renameSquashCycles);
	renameIdleCycles
		.name(name() + ".IdleCycles")
		.desc("Number of cycles rename is idle")
		.prereq(renameIdleCycles);
	renameBlockCycles
		.name(name() + ".BlockCycles")
		.desc("Number of cycles rename is blocking")
		.prereq(renameBlockCycles);
	renameSerializeStallCycles
		.name(name() + ".serializeStallCycles")
		.desc("count of cycles rename stalled for serializing inst")
		.flags(Stats::total);
	renameRunCycles
		.name(name() + ".RunCycles")
		.desc("Number of cycles rename is running")
		.prereq(renameIdleCycles);
	renameUnblockCycles
		.name(name() + ".UnblockCycles")
		.desc("Number of cycles rename is unblocking")
		.prereq(renameUnblockCycles);
	renameRenamedInsts
		.name(name() + ".RenamedInsts")
		.desc("Number of instructions processed by rename")
		.prereq(renameRenamedInsts);
	renameSquashedInsts
		.name(name() + ".SquashedInsts")
		.desc("Number of squashed instructions processed by rename")
		.prereq(renameSquashedInsts);
	renameROBFullEvents
		.name(name() + ".ROBFullEvents")
		.desc("Number of times rename has blocked due to ROB full")
		.prereq(renameROBFullEvents);
	renameIQFullEvents
		.name(name() + ".IQFullEvents")
		.desc("Number of times rename has blocked due to IQ full")
		.prereq(renameIQFullEvents);
	renameLQFullEvents
		.name(name() + ".LQFullEvents")
		.desc("Number of times rename has blocked due to LQ full")
		.prereq(renameLQFullEvents);
	renameSQFullEvents
		.name(name() + ".SQFullEvents")
		.desc("Number of times rename has blocked due to SQ full")
		.prereq(renameSQFullEvents);
	renameFullRegistersEvents
		.name(name() + ".FullRegisterEvents")
		.desc("Number of times there has been no free registers")
		.prereq(renameFullRegistersEvents);
	renameRenamedOperands
		.name(name() + ".RenamedOperands")
		.desc("Number of destination operands rename has renamed")
		.prereq(renameRenamedOperands);
	renameRenameLookups
		.name(name() + ".RenameLookups")
		.desc("Number of register rename lookups that rename has made")
		.prereq(renameRenameLookups);
	renameCommittedMaps
		.name(name() + ".CommittedMaps")
		.desc("Number of HB maps that are committed")
		.prereq(renameCommittedMaps);
	renameUndoneMaps
		.name(name() + ".UndoneMaps")
		.desc("Number of HB maps that are undone due to squashing")
		.prereq(renameUndoneMaps);
	renamedSerializing
		.name(name() + ".serializingInsts")
		.desc("count of serializing insts renamed")
		.flags(Stats::total)
		;
	renamedTempSerializing
		.name(name() + ".tempSerializingInsts")
		.desc("count of temporary serializing insts renamed")
		.flags(Stats::total)
		;
	renameSkidInsts
		.name(name() + ".skidInsts")
		.desc("count of insts added to the skid buffer")
		.flags(Stats::total)
		;
	intRenameLookups
		.name(name() + ".int_rename_lookups")
		.desc("Number of integer rename lookups")
		.prereq(intRenameLookups);
	fpRenameLookups
		.name(name() + ".fp_rename_lookups")
		.desc("Number of floating rename lookups")
		.prereq(fpRenameLookups);
	vecRenameLookups
		.name(name() + ".vec_rename_lookups")
		.desc("Number of vector rename lookups")
		.prereq(vecRenameLookups);
}

template <class Impl>
void
DefaultRename<Impl>::regProbePoints()
{
	ppRename = new ProbePointArg<DynInstPtr>(cpu->getProbeManager(), "Rename");
	ppSquashInRename = new ProbePointArg<SeqNumRegPair>(cpu->getProbeManager(),
		"SquashInRename");
}

template <class Impl>
void
DefaultRename<Impl>::setTimeBuffer(TimeBuffer<TimeStruct> *tb_ptr)
{
	timeBuffer = tb_ptr;

	// Setup wire to read information from time buffer, from IEW stage.
	fromIEW = timeBuffer->getWire(-iewToRenameDelay);

	// Setup wire to read infromation from time buffer, from commit stage.
	fromCommit = timeBuffer->getWire(-commitToRenameDelay);

	// Setup wire to write information to previous stages.
	toDecode = timeBuffer->getWire(0);
}

template <class Impl>
void
DefaultRename<Impl>::setRenameQueue(TimeBuffer<RenameStruct> *rq_ptr)
{
	renameQueue = rq_ptr;

	// Setup wire to write information to future stages.
	toIEW = renameQueue->getWire(0);
}

template <class Impl>
void
DefaultRename<Impl>::setDecodeQueue(TimeBuffer<DecodeStruct> *dq_ptr)
{
	decodeQueue = dq_ptr;

	// Setup wire to get information from decode.
	fromDecode = decodeQueue->getWire(-decodeToRenameDelay);
}

template <class Impl>
void
DefaultRename<Impl>::startupStage()
{
	resetStage();
}

template <class Impl>
void
DefaultRename<Impl>::resetStage()
{
	_status = Inactive;

	resumeSerialize = false;
	resumeUnblocking = false;

	// Grab the number of free entries directly from the stages.
	for (ThreadID tid = 0; tid < numThreads; tid++) {
		renameStatus[tid] = Idle;

		freeEntries[tid].iqEntries = iew_ptr->instQueue.numFreeEntries(tid);
		freeEntries[tid].lqEntries = iew_ptr->ldstQueue.numFreeLoadEntries(tid);
		freeEntries[tid].sqEntries = iew_ptr->ldstQueue.numFreeStoreEntries(tid);
		freeEntries[tid].robEntries = commit_ptr->numROBFreeEntries(tid);
		emptyROB[tid] = true;

		stalls[tid].iew = false;
		serializeInst[tid] = NULL;

		instsInProgress[tid] = 0;
		loadsInProgress[tid] = 0;
		storesInProgress[tid] = 0;

		serializeOnNextInst[tid] = false;
	}
}

template<class Impl>
void
DefaultRename<Impl>::setActiveThreads(list<ThreadID> *at_ptr)
{
	activeThreads = at_ptr;
}


template <class Impl>
void
DefaultRename<Impl>::setRenameMap(RenameMap rm_ptr[])
{
	for (ThreadID tid = 0; tid < numThreads; tid++)
		renameMap[tid] = &rm_ptr[tid];
	//zsx add:
	regPredictTable = new RegPredictTable(64, renameMap[0]->regFile->totalNumRegs);
}

template <class Impl>
void
DefaultRename<Impl>::setFreeList(FreeList *fl_ptr)
{
	freeList = fl_ptr;
}

template<class Impl>
void
DefaultRename<Impl>::setScoreboard(Scoreboard *_scoreboard)
{
	scoreboard = _scoreboard;
}

template <class Impl>
bool
DefaultRename<Impl>::isDrained() const
{
	for (ThreadID tid = 0; tid < numThreads; tid++) {
		if (instsInProgress[tid] != 0 ||
			!historyBuffer[tid].empty() ||
			!skidBuffer[tid].empty() ||
			!insts[tid].empty() ||
			(renameStatus[tid] != Idle && renameStatus[tid] != Running))
			return false;
	}
	return true;
}

template <class Impl>
void
DefaultRename<Impl>::takeOverFrom()
{
	resetStage();
}

template <class Impl>
void
DefaultRename<Impl>::drainSanityCheck() const
{
	for (ThreadID tid = 0; tid < numThreads; tid++) {
		assert(historyBuffer[tid].empty());
		assert(insts[tid].empty());
		assert(skidBuffer[tid].empty());
		assert(instsInProgress[tid] == 0);
	}
}

template <class Impl>
void
DefaultRename<Impl>::squash(const InstSeqNum &squash_seq_num, ThreadID tid)
{
	DPRINTF(Rename, "[tid:%u]: Squashing instructions.\n", tid);

	// Clear the stall signal if rename was blocked or unblocking before.
	// If it still needs to block, the blocking should happen the next
	// cycle and there should be space to hold everything due to the squash.
	if (renameStatus[tid] == Blocked ||
		renameStatus[tid] == Unblocking) {
		toDecode->renameUnblock[tid] = 1;

		resumeSerialize = false;
		serializeInst[tid] = NULL;
	}
	else if (renameStatus[tid] == SerializeStall) {
		if (serializeInst[tid]->seqNum <= squash_seq_num) {
			DPRINTF(Rename, "Rename will resume serializing after squash\n");
				//zsx annotation: if the serialized instruction is older than squash instruction, we cannot squash serializeInst, 
				//we just squash those instructions which is younger than squash_seq_num
				resumeSerialize = true;
			assert(serializeInst[tid]);
		}
		else {
			resumeSerialize = false;
			toDecode->renameUnblock[tid] = 1;

			serializeInst[tid] = NULL;
		}
	}

	// Set the status to Squashing.
	renameStatus[tid] = Squashing;

	// Squash any instructions from decode.
	for (int i = 0; i < fromDecode->size; i++) {
		if (fromDecode->insts[i]->threadNumber == tid &&
			fromDecode->insts[i]->seqNum > squash_seq_num) {
			fromDecode->insts[i]->setSquashed();
			wroteToTimeBuffer = true;
		}

	}

	// Clear the instruction list and skid buffer in case they have any
	// insts in them.
	insts[tid].clear();

	// Clear the skid buffer in case it has any data in it.
	skidBuffer[tid].clear();

	doSquash(squash_seq_num, tid);
}

template <class Impl>
void
DefaultRename<Impl>::tick()
{
	//printf("enter rename stage!\n");
	//DPRINTF(Rename, "enter rename stage:[tid:%i]",tid)
	wroteToTimeBuffer = false;

	blockThisCycle = false;

	bool status_change = false;

	toIEWIndex = 0;

	sortInsts();

	list<ThreadID>::iterator threads = activeThreads->begin();
	list<ThreadID>::iterator end = activeThreads->end();

	// Check stall and squash signals.
	while (threads != end) {
		ThreadID tid = *threads++;

		DPRINTF(Rename, "Processing [tid:%i]\n", tid);
		//printf("begin processing [tid:%i]\n", tid);
		status_change = checkSignalsAndUpdate(tid) || status_change;

		rename(status_change, tid);
	}

	if (status_change) {
		updateStatus();
	}

	if (wroteToTimeBuffer) {
		DPRINTF(Activity, "Activity this cycle.\n");
		cpu->activityThisCycle();
	}

	threads = activeThreads->begin();

	while (threads != end) {
		ThreadID tid = *threads++;

		// If we committed this cycle then doneSeqNum will be > 0
		if (fromCommit->commitInfo[tid].doneSeqNum != 0 &&
			!fromCommit->commitInfo[tid].squash &&
			renameStatus[tid] != Squashing) {
			//DPRINTF(Rename, "begin remove from history buffer.\n");
			removeFromHistory(fromCommit->commitInfo[tid].doneSeqNum,
				tid);
		}
	}

	// @todo: make into updateProgress function
	for (ThreadID tid = 0; tid < numThreads; tid++) {
		instsInProgress[tid] -= fromIEW->iewInfo[tid].dispatched;
		loadsInProgress[tid] -= fromIEW->iewInfo[tid].dispatchedToLQ;
		storesInProgress[tid] -= fromIEW->iewInfo[tid].dispatchedToSQ;
		assert(loadsInProgress[tid] >= 0);
		assert(storesInProgress[tid] >= 0);
		assert(instsInProgress[tid] >= 0);
	}

	//zsx add debug:
	//dumpHistory();

}

template<class Impl>
void
DefaultRename<Impl>::rename(bool &status_change, ThreadID tid)
{
	// If status is Running or idle,
	//     call renameInsts()
	// If status is Unblocking,
	//     buffer any instructions coming from decode
	//     continue trying to empty skid buffer
	//     check if stall conditions have passed

	if (renameStatus[tid] == Blocked) {
		++renameBlockCycles;
	}
	else if (renameStatus[tid] == Squashing) {
		++renameSquashCycles;
	}
	else if (renameStatus[tid] == SerializeStall) {
		++renameSerializeStallCycles;
		// If we are currently in SerializeStall and resumeSerialize
		// was set, then that means that we are resuming serializing
		// this cycle.  Tell the previous stages to block.
		if (resumeSerialize) {
			resumeSerialize = false;
			block(tid);
			toDecode->renameUnblock[tid] = false;
		}
	}
	else if (renameStatus[tid] == Unblocking) {
		if (resumeUnblocking) {
			//zsx debug: change the order of "resumeUnblocking=false;" and block(tid)" 
			resumeUnblocking = false;
			block(tid);
			/*    block(tid);
				resumeUnblocking = false;*/
			toDecode->renameUnblock[tid] = false;
		}
	}

	if (renameStatus[tid] == Running ||
		renameStatus[tid] == Idle) {
		DPRINTF(Rename, "[tid:%u]: Not blocked, so attempting to run "
			"stage.\n", tid);
		//printf("will rename insts:[tid:%u]\n", tid);
		renameInsts(tid);
	}
	else if (renameStatus[tid] == Unblocking) {
		//printf("will rename insts:[tid:%u]\n", tid);
		renameInsts(tid);

		if (validInsts()) {
			// Add the current inputs to the skid buffer so they can be
			// reprocessed when this stage unblocks.
			skidInsert(tid);
		}

		// If we switched over to blocking, then there's a potential for
		// an overall status change.
		status_change = unblock(tid) || status_change || blockThisCycle;
	}
}

template <class Impl>
void
DefaultRename<Impl>::renameInsts(ThreadID tid)
{
	// Instructions can be either in the skid buffer or the queue of
	// instructions coming from decode, depending on the status.
	int insts_available = renameStatus[tid] == Unblocking ?
		skidBuffer[tid].size() : insts[tid].size();

	// Check the decode queue to see if instructions are available.
	// If there are no available instructions to rename, then do nothing.
	if (insts_available == 0) {
		DPRINTF(Rename, "[tid:%u]: Nothing to do, breaking out early.\n",
			tid);
		// Should I change status to idle?
		++renameIdleCycles;
		return;
	}
	else if (renameStatus[tid] == Unblocking) {
		++renameUnblockCycles;
	}
	else if (renameStatus[tid] == Running) {
		++renameRunCycles;
	}

	DynInstPtr inst;

	// Will have to do a different calculation for the number of free
	// entries.
	int free_rob_entries = calcFreeROBEntries(tid);
	int free_iq_entries = calcFreeIQEntries(tid);
	int min_free_entries = free_rob_entries;

	FullSource source = ROB;

	if (free_iq_entries < min_free_entries) {
		min_free_entries = free_iq_entries;
		source = IQ;
	}

	// Check if there's any space left.
	if (min_free_entries <= 0) {
		DPRINTF(Rename, "[tid:%u]: Blocking due to no free ROB/IQ/ "
			"entries.\n"
			"ROB has %i free entries.\n"
			"IQ has %i free entries.\n",
			tid,
			free_rob_entries,
			free_iq_entries);

		blockThisCycle = true;

		block(tid);

		incrFullStat(source);

		return;
	}
	else if (min_free_entries < insts_available) {
		DPRINTF(Rename, "[tid:%u]: Will have to block this cycle."
			"%i insts available, but only %i insts can be "
			"renamed due to ROB/IQ/LSQ limits.\n",
			tid, insts_available, min_free_entries);

		insts_available = min_free_entries;

		blockThisCycle = true;

		incrFullStat(source);
	}

	InstQueue &insts_to_rename = renameStatus[tid] == Unblocking ?
		skidBuffer[tid] : insts[tid];

	DPRINTF(Rename, "[tid:%u]: %i available instructions to "
		"send iew.\n", tid, insts_available);

	DPRINTF(Rename, "[tid:%u]: %i insts pipelining from Rename | %i insts "
		"dispatched to IQ last cycle.\n",
		tid, instsInProgress[tid], fromIEW->iewInfo[tid].dispatched);

	// Handle serializing the next instruction if necessary.
	if (serializeOnNextInst[tid]) {
		if (emptyROB[tid] && instsInProgress[tid] == 0) {
			// ROB already empty; no need to serialize.
			serializeOnNextInst[tid] = false;
		}
		else if (!insts_to_rename.empty()) {
			insts_to_rename.front()->setSerializeBefore();
		}
	}

	int renamed_insts = 0;

	while (insts_available > 0 && toIEWIndex < renameWidth) {
		DPRINTF(Rename, "[tid:%u]: Sending instructions to IEW.\n", tid);

		assert(!insts_to_rename.empty());

		inst = insts_to_rename.front();

		//For all kind of instructions, check ROB and IQ first
		//For load instruction, check LQ size and take into account the inflight loads
		//For store instruction, check SQ size and take into account the inflight stores

		if (inst->isLoad()) {
			if (calcFreeLQEntries(tid) <= 0) {
				DPRINTF(Rename, "[tid:%u]: Cannot rename due to no free LQ\n");
				source = LQ;
				incrFullStat(source);
				break;
			}
		}

		if (inst->isStore()) {
			if (calcFreeSQEntries(tid) <= 0) {
				DPRINTF(Rename, "[tid:%u]: Cannot rename due to no free SQ\n");
				source = SQ;
				incrFullStat(source);
				break;
			}
		}

		insts_to_rename.pop_front();

		if (renameStatus[tid] == Unblocking) {
			DPRINTF(Rename, "[tid:%u]: Removing [sn:%lli] PC:%s from rename "
				"skidBuffer\n", tid, inst->seqNum, inst->pcState());
		}

		if (inst->isSquashed()) {
			DPRINTF(Rename, "[tid:%u]: instruction %i with PC %s is "
				"squashed, skipping.\n", tid, inst->seqNum,
				inst->pcState());

			++renameSquashedInsts;

			// Decrement how many instructions are available.
			--insts_available;

			continue;
		}

		DPRINTF(Rename, "[tid:%u]: Processing instruction [sn:%lli] with "
			"PC %s.\n", tid, inst->seqNum, inst->pcState());

		// Check here to make sure there are enough destination registers
		// to rename to.  Otherwise block.

		//zsx add: check here to make sure all source registers have enough free shadow cell to reuse
		bool free_src_shadow_cell = false;

		ThreadContext *tc = inst->tcBase();
		RenameMap *map = renameMap[tid];
		unsigned num_src_regs = inst->numSrcRegs();

		// Get the architectual register numbers from the source and
	// operands, and redirect them to the right physical register.
		for (int src_idx = 0; src_idx < num_src_regs; src_idx++) {
			const RegId& src_reg = inst->srcRegIdx(src_idx);
			SimpleRenameMap::Rename_Result renamed_reg;

			renamed_reg = map->lookup(tc->flattenRegId(src_reg));
			switch (src_reg.classValue()) {
			case IntRegClass:
				intRenameLookups++;
				break;
			case FloatRegClass:
				fpRenameLookups++;
				break;
			case VecRegClass:
				vecRenameLookups++;
				break;
			case CCRegClass:
			case MiscRegClass:
				break;

			default:
				panic("Invalid register class: %d.", src_reg.classValue());
			}
			
			if(map->regFile->NumFreeShadowCell(renamed_reg.first) > 0)
			//if (map->regFile->whatRegType(renamed_reg.first) - map->regFile->phyRegTable->getTwoBitCounter(renamed_reg.first) > 0)
			{
				//printf("lookup result=%d, instAddr=%lu, sn=%ld, free_src_shadow_cell=true\n", regPredictTable->lookupRegPredTable(inst->instAddr()), inst->instAddr(), inst->seqNum);
				//DPRINTF(Rename, "free_src_shadow_cell=true\n");
				free_src_shadow_cell = true;
			}
		}
		//DPRINTF(Rename, "free_src_shadow_cell=%d\n", free_src_shadow_cell);

		//zsx add:!free_src_shadow_cell

		if (!renameMap[tid]->canRename(inst->numIntDestRegs(),
			inst->numFPDestRegs(),
			inst->numVecDestRegs(),
			inst->numVecElemDestRegs(),
			inst->numCCDestRegs()) && !free_src_shadow_cell) {
			DPRINTF(Rename, "Blocking due to lack of free "
				"physical registers to rename to and no free shadow cells.\n");
			blockThisCycle = true;
			insts_to_rename.push_front(inst);
			++renameFullRegistersEvents;

			break;
		}

		// Handle serializeAfter/serializeBefore instructions.
		// serializeAfter marks the next instruction as serializeBefore.
		// serializeBefore makes the instruction wait in rename until the ROB
		// is empty.

		// In this model, IPR accesses are serialize before
		// instructions, and store conditionals are serialize after
		// instructions.  This is mainly due to lack of support for
		// out-of-order operations of either of those classes of
		// instructions.
		if ((inst->isIprAccess() || inst->isSerializeBefore()) &&
			!inst->isSerializeHandled()) {
			DPRINTF(Rename, "Serialize before instruction encountered.\n");

			if (!inst->isTempSerializeBefore()) {
				renamedSerializing++;
				inst->setSerializeHandled();
			}
			else {
				renamedTempSerializing++;
			}

			// Change status over to SerializeStall so that other stages know
			// what this is blocked on.
			renameStatus[tid] = SerializeStall;

			serializeInst[tid] = inst;

			blockThisCycle = true;

			break;
		}
		else if ((inst->isStoreConditional() || inst->isSerializeAfter()) &&
			!inst->isSerializeHandled()) {
			DPRINTF(Rename, "Serialize after instruction encountered.\n");

			renamedSerializing++;

			inst->setSerializeHandled();

			serializeAfter(insts_to_rename, tid);
		}

		//zsx add:record whether src register are first consumer

		std::vector<bool> src_read_bits(inst->numSrcRegs(), false);

		renameSrcRegs(inst, inst->threadNumber, &src_read_bits);

		renameDestRegs(inst, inst->threadNumber, &src_read_bits);
		src_read_bits.clear();

		if (inst->isLoad()) {
			loadsInProgress[tid]++;
		}
		if (inst->isStore()) {
			storesInProgress[tid]++;
		}
		++renamed_insts;
		// Notify potential listeners that source and destination registers for
		// this instruction have been renamed.
		ppRename->notify(inst);

		// Put instruction in rename queue.
		toIEW->insts[toIEWIndex] = inst;
		++(toIEW->size);

		// Increment which instruction we're on.
		++toIEWIndex;

		// Decrement how many instructions are available.
		--insts_available;
	}

	instsInProgress[tid] += renamed_insts;
	renameRenamedInsts += renamed_insts;

	// If we wrote to the time buffer, record this.
	if (toIEWIndex) {
		wroteToTimeBuffer = true;
	}

	// Check if there's any instructions left that haven't yet been renamed.
	// If so then block.
	if (insts_available) {
		blockThisCycle = true;
	}

	if (blockThisCycle) {
		block(tid);
		toDecode->renameUnblock[tid] = false;
	}
}

template<class Impl>
void
DefaultRename<Impl>::skidInsert(ThreadID tid)
{
	DynInstPtr inst = NULL;

	while (!insts[tid].empty()) {
		inst = insts[tid].front();

		insts[tid].pop_front();

		assert(tid == inst->threadNumber);

		DPRINTF(Rename, "[tid:%u]: Inserting [sn:%lli] PC: %s into Rename "
			"skidBuffer\n", tid, inst->seqNum, inst->pcState());

		++renameSkidInsts;

		skidBuffer[tid].push_back(inst);
	}

	if (skidBuffer[tid].size() > skidBufferMax)
	{
		typename InstQueue::iterator it;
		warn("Skidbuffer contents:\n");
		for (it = skidBuffer[tid].begin(); it != skidBuffer[tid].end(); it++)
		{
			warn("[tid:%u]: %s [sn:%i].\n", tid,
				(*it)->staticInst->disassemble(inst->instAddr()),
				(*it)->seqNum);
		}
		panic("Skidbuffer Exceeded Max Size");
	}
}

template <class Impl>
void
DefaultRename<Impl>::sortInsts()
{
	int insts_from_decode = fromDecode->size;
	for (int i = 0; i < insts_from_decode; ++i) {
		DynInstPtr inst = fromDecode->insts[i];
		insts[inst->threadNumber].push_back(inst);
#if TRACING_ON
		if (DTRACE(O3PipeView)) {
			inst->renameTick = curTick() - inst->fetchTick;
		}
#endif
	}
}

template<class Impl>
bool
DefaultRename<Impl>::skidsEmpty()
{
	list<ThreadID>::iterator threads = activeThreads->begin();
	list<ThreadID>::iterator end = activeThreads->end();

	while (threads != end) {
		ThreadID tid = *threads++;

		if (!skidBuffer[tid].empty())
			return false;
	}

	return true;
}

template<class Impl>
void
DefaultRename<Impl>::updateStatus()
{
	bool any_unblocking = false;

	list<ThreadID>::iterator threads = activeThreads->begin();
	list<ThreadID>::iterator end = activeThreads->end();

	while (threads != end) {
		ThreadID tid = *threads++;

		if (renameStatus[tid] == Unblocking) {
			any_unblocking = true;
			break;
		}
	}

	// Rename will have activity if it's unblocking.
	if (any_unblocking) {
		if (_status == Inactive) {
			_status = Active;

			DPRINTF(Activity, "Activating stage.\n");

			cpu->activateStage(O3CPU::RenameIdx);
		}
	}
	else {
		// If it's not unblocking, then rename will not have any internal
		// activity.  Switch it to inactive.
		if (_status == Active) {
			_status = Inactive;
			DPRINTF(Activity, "Deactivating stage.\n");

			cpu->deactivateStage(O3CPU::RenameIdx);
		}
	}
}

template <class Impl>
bool
DefaultRename<Impl>::block(ThreadID tid)
{
	DPRINTF(Rename, "[tid:%u]: Blocking.\n", tid);

	// Add the current inputs onto the skid buffer, so they can be
	// reprocessed when this stage unblocks.
	skidInsert(tid);

	// Only signal backwards to block if the previous stages do not think
	// rename is already blocked.
	if (renameStatus[tid] != Blocked) {
		// If resumeUnblocking is set, we unblocked during the squash,
		// but now we're have unblocking status. We need to tell earlier
		// stages to block.
		if (resumeUnblocking || renameStatus[tid] != Unblocking) {
			toDecode->renameBlock[tid] = true;
			toDecode->renameUnblock[tid] = false;
			wroteToTimeBuffer = true;
		}

		// Rename can not go from SerializeStall to Blocked, otherwise
		// it would not know to complete the serialize stall.
		if (renameStatus[tid] != SerializeStall) {
			// Set status to Blocked.
			renameStatus[tid] = Blocked;
			return true;
		}
	}

	return false;
}

template <class Impl>
bool
DefaultRename<Impl>::unblock(ThreadID tid)
{
	DPRINTF(Rename, "[tid:%u]: Trying to unblock.\n", tid);

	// Rename is done unblocking if the skid buffer is empty.
	if (skidBuffer[tid].empty() && renameStatus[tid] != SerializeStall) {

		DPRINTF(Rename, "[tid:%u]: Done unblocking.\n", tid);

		toDecode->renameUnblock[tid] = true;
		wroteToTimeBuffer = true;

		renameStatus[tid] = Running;
		return true;
	}

	return false;
}

template <class Impl>
void
DefaultRename<Impl>::doSquash(const InstSeqNum &squashed_seq_num, ThreadID tid)
{
	typename std::list<RenameHistory>::iterator hb_it =
		historyBuffer[tid].begin();
	//zsx add:
	RenameMap *map = renameMap[tid];
	// After a syscall squashes everything, the history buffer may be empty
	// but the ROB may still be squashing instructions.
	if (historyBuffer[tid].empty()) {
		return;
	}

	// Go through the most recent instructions, undoing the mappings
	// they did and freeing up the registers.
	while (!historyBuffer[tid].empty() &&
		hb_it->instSeqNum > squashed_seq_num) {
		assert(hb_it != historyBuffer[tid].end());

		DPRINTF(Rename, "[tid:%u]: Removing history entry with sequence "
			"number %i.\n", tid, hb_it->instSeqNum);

		// Undo the rename mapping only if it was really a change.
		// Special regs that are not really renamed (like misc regs
		// and the zero reg) can be recognized because the new mapping
		// is the same as the old one.  While it would be merely a
		// waste of time to update the rename table, we definitely
		// don't want to put these on the free list.
		if (hb_it->newPhysReg != hb_it->prevPhysReg || (hb_it->newPhysReg == hb_it->prevPhysReg && hb_it->newTwoBitCounter != hb_it->prevTwoBitCounter)) {
			// Tell the rename map to set the architected register to the
			// previous physical register that it was renamed to.

			//zsx debug
			//DPRINTF(Rename, "squash: setEntry in recover history:\n");
			//printf("setEntry in recover history\n");
			renameMap[tid]->setEntry(hb_it->archReg, hb_it->prevPhysReg, hb_it->prevTwoBitCounter);
			//?????????,????????????????
			//printf("setEntry in recover history succeed!\n");
			//DPRINTF(Rename, "squash: setEntry succeed, arch reg=%d, phy reg=%d, sh=%d!\n", hb_it->archReg.index(), hb_it->prevPhysReg->index(), hb_it->prevTwoBitCounter);

			//if(hb_it->newTwoBitCounter > 0)
			//if(hb_it->newTwoBitCounter > 0 && map->regFile->isShadowCellValid(hb_it->newPhysReg, hb_it->newTwoBitCounter))
			//if (hb_it->newTwoBitCounter > 0 && map->regFile->isShadowCellValid(hb_it->newPhysReg, hb_it->newTwoBitCounter -1))
			if(hb_it->newTwoBitCounter > 0 && scoreboard->getReg(hb_it->newPhysReg, hb_it->newTwoBitCounter))
			{
				if (scoreboard->getReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 1))
				{
					//DPRINTF(Rename, "squash: recover reg%d, sh%d\n", hb_it->newPhysReg->index(), hb_it->newTwoBitCounter - 1);
					//map->regFile->RecoverSingleUseReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 1);
					map->regFile->RecoverSingleUseReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 1);
				}
				else if (hb_it->newTwoBitCounter - 2 >= 0 && scoreboard->getReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 2))
				{
					//DPRINTF(Rename, "squash: recover reg%d, sh%d\n", hb_it->newPhysReg->index(), hb_it->newTwoBitCounter - 2);
					//map->regFile->RecoverSingleUseReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 1);
					map->regFile->RecoverSingleUseReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 2);
				}
				else if (hb_it->newTwoBitCounter - 3 >= 0 && scoreboard->getReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 3))
				{
					//DPRINTF(Rename, "squash: recover reg%d, sh%d\n", hb_it->newPhysReg->index(), hb_it->newTwoBitCounter - 3);
					//map->regFile->RecoverSingleUseReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 1);
					map->regFile->RecoverSingleUseReg(hb_it->newPhysReg, hb_it->newTwoBitCounter - 3);
				}
			}
			
			//if(map->regFile->isShadowCellValid(hb_it->prevPhysReg, hb_it->prevTwoBitCounter) && )

			// Put the renamed physical register back on the free list.
			//freeList->addReg(hb_it->newPhysReg);
			map->regFile->FreeShadowCell(hb_it->newPhysReg, hb_it->newTwoBitCounter);

			scoreboard->unsetReg(hb_it->newPhysReg, hb_it->newTwoBitCounter);

			//DPRINTF(Rename, "squash: free reg->index=%d, sh=%d\n", hb_it->newPhysReg->index(), hb_it->newTwoBitCounter);
			//printf("squash: free reg->index=%d, sh=%d\n", hb_it->newPhysReg->index(), hb_it->newTwoBitCounter);
			//zsx add: free reg
			if(map->regFile->isSingleUseRegFree(hb_it->newPhysReg))
			//if (hb_it->newTwoBitCounter == 0 || map->regFile->isSingleUseRegFree(hb_it->newPhysReg))
			{
				freeList->addReg(hb_it->newPhysReg, map->regFile->whatRegType(hb_it->newPhysReg));
				//DPRINTF(Rename, "squash: free reg->index=%d\n", hb_it->newPhysReg->index());
				//printf("squash: free reg->index=%d\n", hb_it->newPhysReg->index());
			}
			/*else if(map->regFile->isSingleUseRegFree(hb_it->newPhysReg))
			{
				//map->regFile->phyRegTable->decTwoBitCounter();
				freeList->addReg(hb_it->newPhysReg, map->regFile->whatRegType(hb_it->newPhysReg));
			}*/
			
	}

		// Notify potential listeners that the register mapping needs to be
		// removed because the instruction it was mapped to got squashed. Note
		// that this is done before hb_it is incremented.
		ppSquashInRename->notify(std::make_pair(hb_it->instSeqNum,
			hb_it->newPhysReg));

		historyBuffer[tid].erase(hb_it++);

		++renameUndoneMaps;
	}
}

template<class Impl>
void
DefaultRename<Impl>::removeFromHistory(InstSeqNum inst_seq_num, ThreadID tid)
{
	DPRINTF(Rename, "[tid:%u]: Removing a committed instruction from the "
		"history buffer %u (size=%i), until [sn:%lli].\n",
		tid, tid, historyBuffer[tid].size(), inst_seq_num);
	//zsx add:
	RenameMap *map = renameMap[tid];

	typename std::list<RenameHistory>::iterator hb_it =
		historyBuffer[tid].end();

	--hb_it;

	if (historyBuffer[tid].empty()) {
		DPRINTF(Rename, "[tid:%u]: History buffer is empty.\n", tid);
		return;
	}
	else if (hb_it->instSeqNum > inst_seq_num) {
		DPRINTF(Rename, "[tid:%u]: Old sequence number encountered.  Ensure "
			"that a syscall happened recently.\n", tid);
		return;
	}

	// Commit all the renames up until (and including) the committed sequence
	// number. Some or even all of the committed instructions may not have
	// rename histories if they did not have destination registers that were
	// renamed.
	while (!historyBuffer[tid].empty() &&
		hb_it != historyBuffer[tid].end() &&
		hb_it->instSeqNum <= inst_seq_num) 
	{

		DPRINTF(Rename, "[tid:%u]: Freeing up older rename of reg %i (%s), "
			"[sn:%lli].\n",
			tid, hb_it->prevPhysReg->index(),
			hb_it->prevPhysReg->className(),
			hb_it->instSeqNum);

		// Don't free special phys regs like misc and zero regs, which
		// can be recognized because the new mapping is the same as
		// the old one.
		if (hb_it->newPhysReg != hb_it->prevPhysReg && map->regFile->whatRegType(hb_it->prevPhysReg) == 0) {
			freeList->addReg(hb_it->prevPhysReg, 0);
			//map->regFile->FreeShadowCell(hb_it->prevPhysReg, 0);
			//DPRINTF(Rename, "commit: free reg->index=%d\n", hb_it->prevPhysReg->index());
			//printf("commit: free reg->index=%d\n", hb_it->prevPhysReg->index());
			map->regFile->phyRegTable->initPhyRegTableEntry(hb_it->prevPhysReg);
		}
		//zsx add: reuse register, how to release shadow cell
		else if (hb_it->newPhysReg != hb_it->prevPhysReg && map->regFile->whatRegType(hb_it->prevPhysReg) != 0)
		{
			int sh_cell = hb_it->prevTwoBitCounter;
			map->regFile->FreeShadowCell(hb_it->prevPhysReg, sh_cell);

			//scoreboard->unsetReg(hb_it->prevPhysReg, sh_cell);

			//DPRINTF(Rename, "commit: free reg->index=%d, sh=%d\n", hb_it->prevPhysReg->index(), sh_cell);
			//printf("commit: free reg->index=%d, sh=%d\n", hb_it->prevPhysReg->index(), sh_cell);


			if (map->regFile->isSingleUseRegFree(hb_it->prevPhysReg))
			{
				freeList->addReg(hb_it->prevPhysReg, map->regFile->whatRegType(hb_it->prevPhysReg));
				//DPRINTF(Rename, "commit: free reg->index=%d\n", hb_it->prevPhysReg->index());
				//printf("commit: free reg->index=%d\n", hb_it->prevPhysReg->index());

				Addr instPC = regPredictTable->PhysRegIndexAddr[hb_it->prevPhysReg->index()];
				//zsx add: update the predictor, because rename and commit is in-order, if reg is completely free, the prevTwoBitCounter indicate its reuse time
				//printf("removing history: lookup result=%d, instAddr=%lx, sn=%ld\n", regPredictTable->lookupRegPredTable(instPC), instPC, hb_it->instSeqNum);
				//if (hb_it->prevTwoBitCounter < map->regFile->whatRegType(hb_it->prevPhysReg) &&
				if(hb_it->prevTwoBitCounter < regPredictTable->lookupRegPredTable(instPC))
				{
					//zsx add: if not all the allocated shadow copies have been used, it means predicted reuse time is bigger than actual reuse time

					regPredictTable->decRegPredTable(instPC);
					//DPRINTF(Rename, "Dec regPredictTable\n");
				}
				else if (hb_it->prevTwoBitCounter > regPredictTable->lookupRegPredTable(instPC))
				{
					//zsx add: if predicted reuse time is less than actual reuset time, (maybe predicted is 0, but actual is 1)
					regPredictTable->incRegPredTable(instPC);
					//DPRINTF(Rename, "Inc regPredictTable\n");
				}
				/*
				else if ()
				{

				}
				else
				*/
				map->regFile->phyRegTable->initPhyRegTableEntry(hb_it->prevPhysReg);
			}

		}
		else if (hb_it->newPhysReg == hb_it->prevPhysReg)
		//else if(hb_it->newPhysReg == hb_it->prevPhysReg && map->regFile->whatRegType(hb_it->prevPhysReg) != 0)
		{
			map->regFile->FreeShadowCell(hb_it->prevPhysReg, hb_it->prevTwoBitCounter);
			//scoreboard->unsetReg(hb_it->prevPhysReg, hb_it->prevTwoBitCounter);
			//DPRINTF(Rename, "commit: free reg->index=%d, sh=%d\n", hb_it->prevPhysReg->index(), hb_it->prevTwoBitCounter);
			//printf("commit: free reg->index=%d, sh=%d\n", hb_it->prevPhysReg->index(), hb_it->prevTwoBitCounter);

			//map->regFile->RecoverSingleUseReg(hb_it->prevPhysReg, hb_it->prevTwoBitCounter);
			if (map->regFile->isSingleUseRegFree(hb_it->prevPhysReg))
			{
				freeList->addReg(hb_it->prevPhysReg, map->regFile->whatRegType(hb_it->prevPhysReg));
				//DPRINTF(Rename, "commit: free reg->index=%d\n", hb_it->prevPhysReg->index());
				//printf("commit: free reg->index=%d\n", hb_it->prevPhysReg->index());


				Addr instPC = regPredictTable->PhysRegIndexAddr[hb_it->prevPhysReg->index()];
				//zsx add: update the predictor, because rename and commit is in-order, if reg is completely free, the prevTwoBitCounter indicate its reuse time
				//printf("removing history: lookup result=%d, instAddr=%lu, sn=%ld\n", regPredictTable->lookupRegPredTable(instPC), instPC, hb_it->instSeqNum);
				if (hb_it->prevTwoBitCounter < map->regFile->whatRegType(hb_it->prevPhysReg) && 
					hb_it->prevTwoBitCounter < regPredictTable->lookupRegPredTable(instPC))
				{
					//zsx add: if not all the allocated shadow copies have been used, it means predicted reuse time is bigger than actual reuse time
					
					regPredictTable->decRegPredTable(instPC);
					//DPRINTF(Rename, "Dec regPredictTable\n");
				}
				else if (hb_it->prevTwoBitCounter > regPredictTable->lookupRegPredTable(instPC))
				{
					//zsx add: if predicted reuse time is less than actual reuset time, (maybe predicted is 0, but actual is 1)
					regPredictTable->incRegPredTable(instPC);
					//DPRINTF(Rename, "Inc regPredictTable\n");
				}
				/*
				else if ()
				{

				}
				else 
				*/
			}
		}
		++renameCommittedMaps;

		historyBuffer[tid].erase(hb_it--);
	}
}

template <class Impl>
inline void
DefaultRename<Impl>::renameSrcRegs(DynInstPtr &inst, ThreadID tid, std::vector<bool> *Src_Read_Bits)
{
	ThreadContext *tc = inst->tcBase();
	RenameMap *map = renameMap[tid];
	unsigned num_src_regs = inst->numSrcRegs();

	// Get the architectual register numbers from the source and
	// operands, and redirect them to the right physical register.
	for (int src_idx = 0; src_idx < num_src_regs; src_idx++) {
		const RegId& src_reg = inst->srcRegIdx(src_idx);

		RegId flat_src_regid = tc->flattenRegId(src_reg);

		SimpleRenameMap::Rename_Result renamed_reg;

		renamed_reg = map->lookup(tc->flattenRegId(src_reg));

		//zsx add: detect regpredicttable misprediction: cannot reuse, but actual reuse
		int wrong_TwoBitCounter = map->regFile->phyRegTable->getTwoBitCounter(renamed_reg.first);
		//renamed_reg.second==0 && map->regFile->phyRegTable->getTwoBitCounter(renamed_reg.first)=1;
		if (renamed_reg.second < wrong_TwoBitCounter)
		{
			//DPRINTF(Rename, "Detected regPredictTable Misprediction: cannot reuse, but actual reuse!\n");
			//DPRINTF(Rename, "reg->index=%d, renamed_reg.second=%d, wrong_twoBitCounter=%d\n", renamed_reg.first->index(), renamed_reg.second, wrong_TwoBitCounter);

			regPredictTable->updateRegPredTable(inst->instAddr(), 0);
			//DPRINTF(Rename, "Update regPredictTable\n");

			PhysRegIdPtr phys_reg2 = NULL;

			//zsx add: if new value has producted, swap the new and past value location
			//if (map->regFile->isShadowCellValid(renamed_reg.first, wrong_TwoBitCounter))
			if(scoreboard->getReg(renamed_reg.first, wrong_TwoBitCounter))
			{
				//DPRINTF(Rename, "new value has producted, swap the new and past value location\n");
				//PhysRegIdPtr phys_reg2;
				if (renamed_reg.first->isIntReg())
				{
					auto temp1 = map->regFile->readIntReg(renamed_reg.first);

					map->regFile->RecoverSingleUseReg(renamed_reg.first, renamed_reg.second);
					auto temp2 = map->regFile->readIntReg(renamed_reg.first);

					if (freeList->intList.hasFreeRegs(0))
					{
						phys_reg2 = freeList->intList.getReg(0);
						/*
						printf("renamed.first->index=%d, type=%d, phys_reg2->index=%d, type=%d\n", renamed_reg.first->index(), map->regFile->whatRegType(renamed_reg.first),
							phys_reg2->index(), map->regFile->whatRegType(phys_reg2));

						DPRINTF(Rename, "renamed.first->index=%d, type=%d, phys_reg2->index=%d, type=%d\n", renamed_reg.first->index(), map->regFile->whatRegType(renamed_reg.first), 
							phys_reg2->index(), map->regFile->whatRegType(phys_reg2));
						*/
						map->regFile->setIntReg(phys_reg2, 0, temp2);

					}
					else
					{
						//zsx add: if there is no such type registers, find other types.
						int min_distance = 3;
						int result_type = 0;
						for (int i = 3; i >= 0; i--)
						{
							if ((i != 0) && (freeList->intList.hasFreeRegs(i)) && (abs(i - 0) <= min_distance))
							{
								min_distance = abs(i - 0);
								result_type = i;
							}
						}
						//printf("result_type=%d\n", result_type);
						phys_reg2 = freeList->intList.getReg(result_type);
						map->regFile->setIntReg(phys_reg2, 0, temp2);
					}


					//phys_reg2 = freeList->getIntReg(0);
					//map->regFile->setIntReg(phys_reg2, 0, temp2);
					map->regFile->setIntReg(renamed_reg.first, wrong_TwoBitCounter, temp1);

				}
				//auto temp1=map->regFile->
				else if (renamed_reg.first->isFloatPhysReg())
				{
					auto temp1 = map->regFile->readFloatReg(renamed_reg.first);
					map->regFile->RecoverSingleUseReg(renamed_reg.first, renamed_reg.second);
					auto temp2 = map->regFile->readFloatReg(renamed_reg.first);

					phys_reg2 = freeList->getFloatReg(0);
					map->regFile->setFloatReg(phys_reg2, 0, temp2);
					map->regFile->setFloatReg(renamed_reg.first, wrong_TwoBitCounter, temp1);
				}
				else if (renamed_reg.first->isVectorPhysReg())
				{
					auto temp1 = map->regFile->readVecReg(renamed_reg.first);
					map->regFile->RecoverSingleUseReg(renamed_reg.first, renamed_reg.second);
					auto temp2 = map->regFile->readVecReg(renamed_reg.first);

					phys_reg2 = freeList->getVecReg(0);
					map->regFile->setVecReg(phys_reg2, 0, temp2);
					map->regFile->setVecReg(renamed_reg.first, wrong_TwoBitCounter, temp1);
				}
				else if (renamed_reg.first->isCCPhysReg())
				{
					auto temp1 = map->regFile->readCCReg(renamed_reg.first);
					map->regFile->RecoverSingleUseReg(renamed_reg.first, renamed_reg.second);
					auto temp2 = map->regFile->readCCReg(renamed_reg.first);

					phys_reg2 = freeList->getCCReg(0);
					map->regFile->setCCReg(phys_reg2, 0, temp2);
					map->regFile->setCCReg(renamed_reg.first, wrong_TwoBitCounter, temp1);
				}
				else
				{
					//printf("unknown register class!\n");
					phys_reg2 = freeList->getIntReg(0);
				}
				//zsx add: these two code need to consider again
				map->regFile->phyRegTable->setReadBit(phys_reg2);
				map->regFile->phyRegTable->initTwoBitCounter(phys_reg2);

				//zsx add: record the mapping between physregindex and addr
				regPredictTable->recordPhysRegIndexAddr(phys_reg2->index(), inst->instAddr());

				//int prevTwoBitCounter = map->regFile->phyRegTable->getTwoBitCounter(renamde_reg.first);

				map->setEntry(src_reg, phys_reg2, 0);
				/*
				inst->SrcNewMap = true;
				BaseO3DynInst::srcregnewmap newMap;
				newMap._flatSrcRegIdx = flat_src_regid;
				newMap.newReg = phys_reg2;
				newMap.newSh_Cell = 0;
				inst->srcRegNewMap.push_back(newMap);
				*/
				scoreboard->setReg(phys_reg2, 0);
				scoreboard->setReg(renamed_reg.first, wrong_TwoBitCounter);
				scoreboard->setReg(renamed_reg.first, renamed_reg.second);

				
				RenameHistory hb_entry(inst->seqNum, flat_src_regid,
					phys_reg2,
					0,
					renamed_reg.first,
					renamed_reg.second
				);
				//inst->instAddr());

				/*historyBuffer[tid].push_front(hb_entry);
				DPRINTF(Rename, "[tid:%u]: Adding instruction to history buffer "
					"(size=%i), [sn:%lli].\n", tid,
					historyBuffer[tid].size(),
					(*historyBuffer[tid].begin()).instSeqNum);
				*/



				inst->renameSrcReg(src_idx,
					phys_reg2,
					0);

				DPRINTF(Rename, "[tid:%u]: Looking up %s arch reg %i"
					", got phys reg %i (%s) counter=%d\n", tid,
					src_reg.className(), src_reg.index(),
					phys_reg2->index(),
					phys_reg2->className(),
					0);

				if (scoreboard->getReg(phys_reg2, 0))
				{
					//if(scoreboard->getReg(renamed_reg.first))
					DPRINTF(Rename, "[tid:%u]: Register %d (flat: %d) (%s)"
						" is ready.\n", tid, phys_reg2->index(),
						phys_reg2->flatIndex(),
						phys_reg2->className());
					map->regFile->setShadowCellValid(phys_reg2, 0);
					inst->markSrcRegReady(src_idx);
				}
				else {
					DPRINTF(Rename, "[tid:%u]: Register %d (flat: %d) (%s)"
						" is not ready.\n", tid, phys_reg2->index(),
						phys_reg2->flatIndex(),
						phys_reg2->className());
				}

			}


			else
			{
				//PhysRegIdPtr phys_reg2;
				//zsx add: if the past value has producted, allocate a new reg and copy the value to new reg
				//if (map->regFile->isShadowCellValid(renamed_reg.first, renamed_reg.second))
				if(scoreboard->getReg(renamed_reg.first, renamed_reg.second))
				{
					//DPRINTF(Rename, "the past value has producted, allocate a new reg and copy the value to new reg\n");
					if (renamed_reg.first->isIntReg())
					{
						auto temp1 = map->regFile->readIntReg(renamed_reg.first);
						phys_reg2 = freeList->getIntReg(0);
						map->regFile->setIntReg(phys_reg2, 0, temp1);
					}
					//auto temp1=map->regFile->
					else if (renamed_reg.first->isFloatPhysReg())
					{
						auto temp1 = map->regFile->readFloatReg(renamed_reg.first);
						phys_reg2 = freeList->getFloatReg(0);
						map->regFile->setFloatReg(phys_reg2, 0, temp1);
					}
					else if (renamed_reg.first->isVectorPhysReg())
					{
						auto temp1 = map->regFile->readVecReg(renamed_reg.first);
						phys_reg2 = freeList->getVecReg(0);
						map->regFile->setVecReg(phys_reg2, 0, temp1);
					}
					else if (renamed_reg.first->isCCPhysReg())
					{
						auto temp1 = map->regFile->readCCReg(renamed_reg.first);
						phys_reg2 = freeList->getCCReg(0);
						map->regFile->setCCReg(phys_reg2, 0, temp1);
					}

					else
					{
						//printf("unknown register class!\n");
						phys_reg2 = freeList->getIntReg(0);
					}
					scoreboard->setReg(phys_reg2, 0);


					//zsx add: these two code need to consider again
					map->regFile->phyRegTable->setReadBit(phys_reg2);
					map->regFile->phyRegTable->initTwoBitCounter(phys_reg2);

					//zsx add: record the mapping between physregindex and addr
					regPredictTable->recordPhysRegIndexAddr(phys_reg2->index(), inst->instAddr());

					//int prevTwoBitCounter = map->regFile->phyRegTable->getTwoBitCounter(renamde_reg.first);

					map->setEntry(src_reg, phys_reg2, 0);
					//scoreboard->setReg(renamed_reg.first);

					
					RenameHistory hb_entry(inst->seqNum, flat_src_regid,
						phys_reg2,
						0,
						renamed_reg.first,
						renamed_reg.second
					);
					//inst->instAddr());
					/*
					historyBuffer[tid].push_front(hb_entry);
					DPRINTF(Rename, "[tid:%u]: Adding instruction to history buffer "
						"(size=%i), [sn:%lli].\n", tid,
						historyBuffer[tid].size(),
						(*historyBuffer[tid].begin()).instSeqNum);
					*/




					inst->renameSrcReg(src_idx,
						phys_reg2,
						0);


					DPRINTF(Rename, "[tid:%u]: Looking up %s arch reg %i"
						", got phys reg %i (%s) counter=%d\n", tid,
						src_reg.className(), src_reg.index(),
						phys_reg2->index(),
						phys_reg2->className(),
						0);

					if (scoreboard->getReg(phys_reg2, 0))
					{
						//if(scoreboard->getReg(renamed_reg.first))
						DPRINTF(Rename, "[tid:%u]: Register %d (flat: %d) (%s)"
							" is ready.\n", tid, phys_reg2->index(),
							phys_reg2->flatIndex(),
							phys_reg2->className());

						map->regFile->setShadowCellValid(phys_reg2, 0);
						inst->markSrcRegReady(src_idx);
					}
					else {
						DPRINTF(Rename, "[tid:%u]: Register %d (flat: %d) (%s)"
							" is not ready.\n", tid, phys_reg2->index(),
							phys_reg2->flatIndex(),
							phys_reg2->className());
					}
				}
				
				else
				{
					//DPRINTF(Rename, "the past value has not producted, allocate a new reg\n");

					//inst->setSquashed();
					//fromCommit->commitInfo[tid].squash = true;
					//fromCommit->commitInfo[tid].doneSeqNum = inst->seqNum;
					//inst->mispredicted();
					if (renamed_reg.first->isIntReg())
					{
						//auto temp1 = map->regFile->readIntReg(renamed_reg.first);
						phys_reg2 = freeList->getIntReg(0);
						//map->regFile->setIntReg(phys_reg2, 0, temp1);
					}
					//auto temp1=map->regFile->
					else if (renamed_reg.first->isFloatPhysReg())
					{
						//auto temp1 = map->regFile->readFloatReg(renamed_reg.first);
						phys_reg2 = freeList->getFloatReg(0);
						//map->regFile->setFloatReg(phys_reg2, 0, temp1);
					}
					else if (renamed_reg.first->isVectorPhysReg())
					{
						//auto temp1 = map->regFile->readVecReg(renamed_reg.first);
						phys_reg2 = freeList->getVecReg(0);
						//map->regFile->setVecReg(phys_reg2, 0, temp1);
					}
					else if (renamed_reg.first->isCCPhysReg())
					{
						//auto temp1 = map->regFile->readCCReg(renamed_reg.first);
						phys_reg2 = freeList->getCCReg(0);
						//map->regFile->setCCReg(phys_reg2, 0, temp1);
					}

					else
					{
						//printf("unknown register class!\n");
						phys_reg2 = freeList->getIntReg(0);
					}

					//zsx add: these two code need to consider again
					map->regFile->phyRegTable->setReadBit(phys_reg2);
					map->regFile->phyRegTable->initTwoBitCounter(phys_reg2);

					//zsx add: record the mapping between physregindex and addr
					regPredictTable->recordPhysRegIndexAddr(phys_reg2->index(), inst->instAddr());

					//int prevTwoBitCounter = map->regFile->phyRegTable->getTwoBitCounter(renamde_reg.first);

					map->setEntry(src_reg, phys_reg2, 0);
					
					inst->renameSrcReg(src_idx,
						phys_reg2,
						0);


					DPRINTF(Rename, "[tid:%u]: Looking up %s arch reg %i"
						", got phys reg %i (%s) counter=%d\n", tid,
						src_reg.className(), src_reg.index(),
						phys_reg2->index(),
						phys_reg2->className(),
						0);

					//map->regFile->setShadowCellValid(phys_reg2, 0);

					/*
					if (scoreboard->getReg(phys_reg2))
					{
						//if(scoreboard->getReg(renamed_reg.first))
						DPRINTF(Rename, "[tid:%u]: Register %d (flat: %d) (%s)"
							" is ready.\n", tid, phys_reg2->index(),
							phys_reg2->flatIndex(),
							phys_reg2->className());

						//map->regFile->setShadowCellValid(phys_reg2, 0);
						//inst->markSrcRegReady(src_idx);
					}
					else {
						DPRINTF(Rename, "[tid:%u]: Register %d (flat: %d) (%s)"
							" is not ready.\n", tid, phys_reg2->index(),
							phys_reg2->flatIndex(),
							phys_reg2->className());
					}
					*/
					inst->RecoverFromLastWrite = true;
					inst->recoverData.src_idx = src_idx;
					inst->recoverData.srcReg = renamed_reg.first;
					inst->recoverData.wrongSh_Cell = wrong_TwoBitCounter;
					inst->recoverData.rightSh_Cell = renamed_reg.second;
					inst->recoverData.newReg = phys_reg2;
					inst->recoverData.newSh_Cell = 0;
					//DPRINTF(Rename, "set recover flag RecoverFromLastWrite=%d sn=%ld\n", inst->RecoverFromLastWrite, inst->seqNum);
					scoreboard->unsetReg(phys_reg2, 0);
					//map->regFile->setShadowCellValid(phys_reg2, 0);
					//inst->markSrcRegReady(src_idx);
					/*
					//zsx add: change the past instruction mapping
					for (int i = 0; i < historyBuffer.size(); i++)
					{
						if (historyBuffer[i].newPhysReg == renamed_reg.first && historyBuffer[i].newTwoBitCounter == renamed_reg.second)
						{
							historyBuffer[i].newPhysReg = phys_reg2;
							historyBuffer[i].newTwoBitCounter = 0;
						}
					}
					*/
				}
			}
			inst->SrcNewMap = true;
			typename DynInst::srcregnewmap newMap;
			newMap._flatSrcRegIdx = flat_src_regid;
			newMap.newReg = phys_reg2;
			newMap.newSh_Cell = 0;
			inst->srcRegNewMap.push_back(newMap);
			//DPRINTF(Rename, "set newsrcmap flag inst->SrcNewMap=%d sn=%ld\n", inst->SrcNewMap, inst->seqNum);
		}
		else
		{
			//zsx add: read src register read bit and record it
			(*Src_Read_Bits)[src_idx] = map->regFile->phyRegTable->getReadBit(renamed_reg.first);

			if ((*Src_Read_Bits)[src_idx] == true)
			{
				//printf("src_read_bits[%d]=true\n", src_idx);
				//DPRINTF(Rename, "src_read_bits[%d]=true\n", src_idx);
			}
			
			else if ((*Src_Read_Bits)[src_idx] == false)
			{
				//printf("src_read_bits[%d]=false\n", src_idx);
				//DPRINTF(Rename, "src_read_bits[%d]=false\n", src_idx);

				map->regFile->phyRegTable->setReadBit(renamed_reg.first);

				if (map->regFile->phyRegTable->getReadBit(renamed_reg.first) == true)
				{
					//printf("After set: src_read_bits[%d]=true\n", src_idx);
					//DPRINTF(Rename, "After set: src_read_bits[%d]=true\n", src_idx);
				}
				else
				{
					//printf("After set: src_read_bits[%d]=false\n", src_idx);
					//DPRINTF(Rename, "After set: src_read_bits[%d]=false\n", src_idx);
				}
			}



			switch (src_reg.classValue()) {
			case IntRegClass:
				intRenameLookups++;
				break;
			case FloatRegClass:
				fpRenameLookups++;
				break;
			case VecRegClass:
				vecRenameLookups++;
				break;
			case CCRegClass:
			case MiscRegClass:
				break;

			default:
				panic("Invalid register class: %d.", src_reg.classValue());
			}

			DPRINTF(Rename, "[tid:%u]: Looking up %s arch reg %i"
				", got phys reg %i (%s) counter=%d\n", tid,
				src_reg.className(), src_reg.index(),
				renamed_reg.first->index(),
				renamed_reg.first->className(),
				renamed_reg.second);

			inst->renameSrcReg(src_idx, renamed_reg.first, renamed_reg.second);

			//zsx change:
			// See if the register is ready or not.
			//if (map->regFile->isShadowCellValid(renamed_reg.first, map->regFile->phyRegTable->getTwoBitCounter(renamed_reg.first)))
			if (scoreboard->getReg(renamed_reg.first, renamed_reg.second))
			{
				//if(scoreboard->getReg(renamed_reg.first))
				DPRINTF(Rename, "[tid:%u]: Register %d (flat: %d) (%s) sh%d"
					" is ready.\n", tid, renamed_reg.first->index(),
					renamed_reg.first->flatIndex(),
					renamed_reg.first->className(), renamed_reg.second);
				
				map->regFile->setShadowCellValid(renamed_reg.first, renamed_reg.second);
				inst->markSrcRegReady(src_idx);
			}
			else {
				DPRINTF(Rename, "[tid:%u]: Register %d (flat: %d) (%s) sh%d"
					" is not ready.\n", tid, renamed_reg.first->index(),
					renamed_reg.first->flatIndex(),
					renamed_reg.first->className(), renamed_reg.second);
			}

			++renameRenameLookups;
		}
	}
}

template <class Impl>
inline void
DefaultRename<Impl>::renameDestRegs(DynInstPtr &inst, ThreadID tid, std::vector<bool> *Src_Read_Bits)
{
	ThreadContext *tc = inst->tcBase();
	RenameMap *map = renameMap[tid];
	unsigned num_dest_regs = inst->numDestRegs();

	//zsx add: find if there is first consumers in src regs
	bool has_src_first_consumers = false;
	std::vector<std::pair<PhysRegIdPtr, RegId>> src_first_consumers_index;

	//DPRINTF(Rename, "src_read_bit=\n");
	for (int i = 0; i < Src_Read_Bits->size(); i++)
	{
		if ((*Src_Read_Bits)[i] == false)
		{
			std::pair<PhysRegIdPtr, RegId> src_first_consumer_pair = std::make_pair(map->lookup(tc->flattenRegId(inst->srcRegIdx(i))).first, tc->flattenRegId(inst->srcRegIdx(i)));
			src_first_consumers_index.push_back(src_first_consumer_pair);
			has_src_first_consumers = true;
			//DPRINTF(Rename, "reg[%d](%s) = false\n", src_first_consumer_pair.first->index(), src_first_consumer_pair.first->className());
			//break;
		}
		//else
			//DPRINTF(Rename, "true\n");
	}

	//zsx add: if there is no first consumers in src regs, allocate new phy reg for destRegs
	if (!has_src_first_consumers)
	{
		// Rename the destination registers.
		for (int dest_idx = 0; dest_idx < num_dest_regs; dest_idx++) {
			const RegId& dest_reg = inst->destRegIdx(dest_idx);
			typename RenameMap::RenameInfo rename_result;

			RegId flat_dest_regid = tc->flattenRegId(dest_reg);

			//zsx add: look up in RegPredictTable to know what kind of register to allocate
			int regType = regPredictTable->lookupRegPredTable(inst->instAddr());
			//printf("allocating new reg, regType=%d, instAddr=%lu, sn=%ld\n", regType, inst->instAddr(), inst->seqNum);


			rename_result = map->rename(flat_dest_regid, regType);
			//zsx add: record new allocated register's main_cell as "allocated" status
			map->regFile->setShadowCellAllocated(rename_result.first.first, 0);

			map->regFile->phyRegTable->unsetReadBit(rename_result.first.first);
			map->regFile->phyRegTable->initTwoBitCounter(rename_result.first.first);

			//zsx add: record the mapping between physregindex and addr
			regPredictTable->recordPhysRegIndexAddr(rename_result.first.first->index(), inst->instAddr());

			inst->flattenDestReg(dest_idx, flat_dest_regid);

			// Mark Scoreboard entry as not ready
			scoreboard->unsetReg(rename_result.first.first, rename_result.first.second);

			DPRINTF(Rename, "[tid:%u]: Renaming arch reg %i (%s) to physical "
				"reg %i (%i) counter=%d.\n", tid, dest_reg.index(),
				dest_reg.className(),
				rename_result.first.first->index(),
				rename_result.first.first->flatIndex(),
				rename_result.first.second);

			// Record the rename information so that a history can be kept.
			RenameHistory hb_entry(inst->seqNum, flat_dest_regid,
				rename_result.first.first,
				rename_result.first.second,
				rename_result.second.first,
				rename_result.second.second
				);
				//inst->instAddr());

			historyBuffer[tid].push_front(hb_entry);

			DPRINTF(Rename, "[tid:%u]: Adding instruction to history buffer "
				"(size=%i), [sn:%lli].\n", tid,
				historyBuffer[tid].size(),
				(*historyBuffer[tid].begin()).instSeqNum);

			// Tell the instruction to rename the appropriate destination
			// register (dest_idx) to the new physical register
			// (rename_result.first), and record the previous physical
			// register that the same logical register was renamed to
			// (rename_result.second).
			inst->renameDestReg(dest_idx,
				rename_result.first.first,
				rename_result.second.first,
				rename_result.first.second,
				rename_result.second.second);

			++renameRenamedOperands;
		}
	}
	
	//zsx add: if there is possibility of reuse
	else
	{
		for (int dest_idx = 0; dest_idx < num_dest_regs; dest_idx++)
		{
			int i;
			int reuse_success = false;
			for (i = 0; i < src_first_consumers_index.size(); i++)
			{
				const RegId& dest_reg = inst->destRegIdx(dest_idx);
				RegId flat_dest_regid = tc->flattenRegId(dest_reg);

				std::pair<PhysRegIdPtr, RegId> src_fc_idx = src_first_consumers_index[i];

				//renamed_reg = map->lookup(tc->flattenRegId(src_reg));
				//printf("lookup result=%d, instAddr=%lu, sn=%ld\n", regPredictTable->lookupRegPredTable(inst->instAddr()), inst->instAddr(), inst->seqNum);
				//zsx add: under what conditions can reuser src physical register
				if (map->regFile->phyRegTable->getTwoBitCounter(src_fc_idx.first) < 3  && 
					//(regPredictTable->lookupRegPredTable(inst->instAddr()) > map->regFile->phyRegTable->getTwoBitCounter(src_fc_idx.first))
				    map->regFile->NumFreeShadowCell(src_fc_idx.first) > 0
					//map->regFile->phyRegTable->getTwoBitCounter(src_fc_idx.first)
					//((inst->srcRegIdx(i) == inst->destRegIdx(dest_idx)) && 
					&& flat_dest_regid.classValue() == src_fc_idx.second.classValue())
				{
					SimpleRenameMap::Rename_Result HistoryMap = map->lookup(flat_dest_regid);
					//printf("twoBitCounter=%d, num_free_sh=%d\n", map->regFile->phyRegTable->getTwoBitCounter(src_fc_idx.first), map->regFile->NumFreeShadowCell(src_fc_idx.first));
					//zsx add: reuse src phy register
					inst->flattenDestReg(dest_idx, flat_dest_regid);
					int prevTwoBitCounter = map->regFile->phyRegTable->getTwoBitCounter(src_fc_idx.first);

					//zsx debug
					//DPRINTF(Rename, "setEntry in rename dest reg:\n");
					//printf("setEntry the PhysRegIdPtr index=%d, className=%s, [sn:%ld]\n", src_fc_idx.first->index(), src_fc_idx.first->className(), inst->seqNum);
					//zsx change:
					map->setEntry(dest_reg, src_fc_idx.first, prevTwoBitCounter + 1);
					//map->setEntry(flat_dest_regid, src_fc_idx.first, prevTwoBitCounter + 1);

					//zsx add: record reuse register's shadow_cell as "allocated" status
					map->regFile->setShadowCellAllocated(src_fc_idx.first, prevTwoBitCounter + 1);


					//DPRINTF(Rename, "setEntry succeed! reuse succeed\n");
					map->regFile->phyRegTable->incTwoBitCounter(src_fc_idx.first);

					int newTwoBitCounter = map->regFile->phyRegTable->getTwoBitCounter(src_fc_idx.first);
					map->regFile->phyRegTable->setReadBit(src_fc_idx.first);

					//UnifiedRenameMap::RenameInfo rename_result = std::make_pair(std::make_pair(src_fc_idx.first, newTwoBitCounter), map->lookup(src_fc_idx.second));
					UnifiedRenameMap::RenameInfo rename_result = std::make_pair(std::make_pair(src_fc_idx.first, newTwoBitCounter), HistoryMap);
					//map->regFile[src_fc_idx->index()].sh_free[TwoBitCounter] = false;

					//zsx Q: whether to unset scoreboard? but dest and src map to the same reg? how to tell?
					scoreboard->unsetReg(rename_result.first.first, rename_result.first.second);

					DPRINTF(Rename, "[tid:%u]: Reuse: Renaming arch reg %i (%s) to physical "
						"reg %i (%i) counter=%d.\n", tid, dest_reg.index(),
						dest_reg.className(),
						rename_result.first.first->index(),
						rename_result.first.first->flatIndex(),
						rename_result.first.second);

					// Record the rename information so that a history can be kept.
					RenameHistory hb_entry(inst->seqNum, flat_dest_regid,
						rename_result.first.first,
						rename_result.first.second,
						rename_result.second.first,
						rename_result.second.second
						);
						//inst->instAddr());

					historyBuffer[tid].push_front(hb_entry);

					DPRINTF(Rename, "[tid:%u]: Adding instruction to history buffer "
						"(size=%i), [sn:%lli].\n", tid,
						historyBuffer[tid].size(),
						(*historyBuffer[tid].begin()).instSeqNum);

					// Tell the instruction to rename the appropriate destination
					// register (dest_idx) to the new physical register
					// (rename_result.first), and record the previous physical
					// register that the same logical register was renamed to
					// (rename_result.second).
					inst->renameDestReg(dest_idx,
						rename_result.first.first,
						rename_result.second.first,
						rename_result.first.second,
						rename_result.second.second);

					++renameRenamedOperands;
					reuse_success = true;

					//zsx add: forbid: two dest regs reuse the same src twice
					std::vector<std::pair<PhysRegIdPtr, RegId>>::iterator it = src_first_consumers_index.begin() + i;
					//if (it!=NULL)
					{
						src_first_consumers_index.erase(it);
					}
					break;
				}
				
			}


			//zsx add: if reuse unsucceed, allocate a new register for it
			if (i == src_first_consumers_index.size() && !reuse_success)
			{
				//for (int dest_idx = 0; dest_idx < num_dest_regs; dest_idx++) {
				const RegId& dest_reg = inst->destRegIdx(dest_idx);
				typename RenameMap::RenameInfo rename_result;

				RegId flat_dest_regid = tc->flattenRegId(dest_reg);

				//zsx add: look up in RegPredictTable to know what kind of register to allocate
				int regType = regPredictTable->lookupRegPredTable(inst->instAddr());
				//printf("allocating new reg, regType=%d, instAddr=%lu, sn=%ld\n", regType, inst->instAddr(), inst->seqNum);

				rename_result = map->rename(flat_dest_regid, regType);

				//zsx add: record new allocated register's main_cell as "allocated" status
				map->regFile->setShadowCellAllocated(rename_result.first.first, 0);

				map->regFile->phyRegTable->unsetReadBit(rename_result.first.first);
				map->regFile->phyRegTable->initTwoBitCounter(rename_result.first.first);

				//zsx add: record the mapping between physregindex and addr
				regPredictTable->recordPhysRegIndexAddr(rename_result.first.first->index(), inst->instAddr());


				inst->flattenDestReg(dest_idx, flat_dest_regid);

				// Mark Scoreboard entry as not ready
				scoreboard->unsetReg(rename_result.first.first, rename_result.first.second);

				DPRINTF(Rename, "[tid:%u]: Renaming arch reg %i (%s) to physical "
					"reg %i (%i) counter=%d.\n", tid, dest_reg.index(),
					dest_reg.className(),
					rename_result.first.first->index(),
					rename_result.first.first->flatIndex(),
					rename_result.first.second);

				// Record the rename information so that a history can be kept.
				RenameHistory hb_entry(inst->seqNum, flat_dest_regid,
					rename_result.first.first,
					rename_result.first.second,
					rename_result.second.first,
					rename_result.second.second
					);
					//inst->instAddr());

				historyBuffer[tid].push_front(hb_entry);

				DPRINTF(Rename, "[tid:%u]: Adding instruction to history buffer "
					"(size=%i), [sn:%lli].\n", tid,
					historyBuffer[tid].size(),
					(*historyBuffer[tid].begin()).instSeqNum);

				// Tell the instruction to rename the appropriate destination
				// register (dest_idx) to the new physical register
				// (rename_result.first), and record the previous physical
				// register that the same logical register was renamed to
				// (rename_result.second).
				inst->renameDestReg(dest_idx,
					rename_result.first.first,
					rename_result.second.first,
					rename_result.first.second,
					rename_result.second.second);

				++renameRenamedOperands;
				
			}
		}
	}
}



template <class Impl>
inline int
DefaultRename<Impl>::calcFreeROBEntries(ThreadID tid)
{
	int num_free = freeEntries[tid].robEntries -
		(instsInProgress[tid] - fromIEW->iewInfo[tid].dispatched);

	//DPRINTF(Rename,"[tid:%i]: %i rob free\n",tid,num_free);

	return num_free;
}

template <class Impl>
inline int
DefaultRename<Impl>::calcFreeIQEntries(ThreadID tid)
{
	int num_free = freeEntries[tid].iqEntries -
		(instsInProgress[tid] - fromIEW->iewInfo[tid].dispatched);

	//DPRINTF(Rename,"[tid:%i]: %i iq free\n",tid,num_free);

	return num_free;
}

template <class Impl>
inline int
DefaultRename<Impl>::calcFreeLQEntries(ThreadID tid)
{
	int num_free = freeEntries[tid].lqEntries -
		(loadsInProgress[tid] - fromIEW->iewInfo[tid].dispatchedToLQ);
	DPRINTF(Rename, "calcFreeLQEntries: free lqEntries: %d, loadsInProgress: %d, "
		"loads dispatchedToLQ: %d\n", freeEntries[tid].lqEntries,
		loadsInProgress[tid], fromIEW->iewInfo[tid].dispatchedToLQ);
	return num_free;
}

template <class Impl>
inline int
DefaultRename<Impl>::calcFreeSQEntries(ThreadID tid)
{
	int num_free = freeEntries[tid].sqEntries -
		(storesInProgress[tid] - fromIEW->iewInfo[tid].dispatchedToSQ);
	DPRINTF(Rename, "calcFreeSQEntries: free sqEntries: %d, storesInProgress: %d, "
		"stores dispatchedToSQ: %d\n", freeEntries[tid].sqEntries,
		storesInProgress[tid], fromIEW->iewInfo[tid].dispatchedToSQ);
	return num_free;
}

template <class Impl>
unsigned
DefaultRename<Impl>::validInsts()
{
	unsigned inst_count = 0;

	for (int i = 0; i < fromDecode->size; i++) {
		if (!fromDecode->insts[i]->isSquashed())
			inst_count++;
	}

	return inst_count;
}

template <class Impl>
void
DefaultRename<Impl>::readStallSignals(ThreadID tid)
{
	if (fromIEW->iewBlock[tid]) {
		stalls[tid].iew = true;
	}

	if (fromIEW->iewUnblock[tid]) {
		assert(stalls[tid].iew);
		stalls[tid].iew = false;
	}
}

template <class Impl>
bool
DefaultRename<Impl>::checkStall(ThreadID tid)
{
	bool ret_val = false;

	if (stalls[tid].iew) {
		DPRINTF(Rename, "[tid:%i]: Stall from IEW stage detected.\n", tid);
		ret_val = true;
	}
	else if (calcFreeROBEntries(tid) <= 0) {
		DPRINTF(Rename, "[tid:%i]: Stall: ROB has 0 free entries.\n", tid);
		ret_val = true;
	}
	else if (calcFreeIQEntries(tid) <= 0) {
		DPRINTF(Rename, "[tid:%i]: Stall: IQ has 0 free entries.\n", tid);
		ret_val = true;
	}
	else if (calcFreeLQEntries(tid) <= 0 && calcFreeSQEntries(tid) <= 0) {
		DPRINTF(Rename, "[tid:%i]: Stall: LSQ has 0 free entries.\n", tid);
		ret_val = true;
	}
	else if (renameMap[tid]->numMinFreeEntries() <= 0) {
		DPRINTF(Rename, "[tid:%i]: Stall: RenameMap has 0 free entries.\n", tid);
		ret_val = true;
	}
	else if (renameStatus[tid] == SerializeStall &&
		(!emptyROB[tid] || instsInProgress[tid])) {
		DPRINTF(Rename, "[tid:%i]: Stall: Serialize stall and ROB is not "
			"empty.\n",
			tid);
		ret_val = true;
	}

	return ret_val;
}

template <class Impl>
void
DefaultRename<Impl>::readFreeEntries(ThreadID tid)
{
	if (fromIEW->iewInfo[tid].usedIQ)
		freeEntries[tid].iqEntries = fromIEW->iewInfo[tid].freeIQEntries;

	if (fromIEW->iewInfo[tid].usedLSQ) {
		freeEntries[tid].lqEntries = fromIEW->iewInfo[tid].freeLQEntries;
		freeEntries[tid].sqEntries = fromIEW->iewInfo[tid].freeSQEntries;
	}

	if (fromCommit->commitInfo[tid].usedROB) {
		freeEntries[tid].robEntries =
			fromCommit->commitInfo[tid].freeROBEntries;
		emptyROB[tid] = fromCommit->commitInfo[tid].emptyROB;
	}

	DPRINTF(Rename, "[tid:%i]: Free IQ: %i, Free ROB: %i, "
		"Free LQ: %i, Free SQ: %i, FreeRM %i(%i %i %i %i)\n",
		tid,
		freeEntries[tid].iqEntries,
		freeEntries[tid].robEntries,
		freeEntries[tid].lqEntries,
		freeEntries[tid].sqEntries,
		renameMap[tid]->numMinFreeEntries(),
		renameMap[tid]->numMinFreeIntEntries(),
		renameMap[tid]->numMinFreeFloatEntries(),
		renameMap[tid]->numMinFreeVecEntries(),
		renameMap[tid]->numMinFreeCCEntries());

	DPRINTF(Rename, "[tid:%i]: %i instructions not yet in ROB\n",
		tid, instsInProgress[tid]);
}

template <class Impl>
bool
DefaultRename<Impl>::checkSignalsAndUpdate(ThreadID tid)
{
	// Check if there's a squash signal, squash if there is
	// Check stall signals, block if necessary.
	// If status was blocked
	//     check if stall conditions have passed
	//         if so then go to unblocking
	// If status was Squashing
	//     check if squashing is not high.  Switch to running this cycle.
	// If status was serialize stall
	//     check if ROB is empty and no insts are in flight to the ROB

	readFreeEntries(tid);
	readStallSignals(tid);

	if (fromCommit->commitInfo[tid].squash) {
		DPRINTF(Rename, "[tid:%u]: Squashing instructions due to squash from "
			"commit.\n", tid);

		squash(fromCommit->commitInfo[tid].doneSeqNum, tid);

		return true;
	}

	if (checkStall(tid)) {
		return block(tid);
	}

	if (renameStatus[tid] == Blocked) {
		DPRINTF(Rename, "[tid:%u]: Done blocking, switching to unblocking.\n",
			tid);

		renameStatus[tid] = Unblocking;

		unblock(tid);

		return true;
	}

	if (renameStatus[tid] == Squashing) {
		// Switch status to running if rename isn't being told to block or
		// squash this cycle.
		if (resumeSerialize) {
			DPRINTF(Rename, "[tid:%u]: Done squashing, switching to serialize.\n",
				tid);

			renameStatus[tid] = SerializeStall;
			return true;
		}
		else if (resumeUnblocking) {
			DPRINTF(Rename, "[tid:%u]: Done squashing, switching to unblocking.\n",
				tid);
			renameStatus[tid] = Unblocking;
			return true;
		}
		else {
			DPRINTF(Rename, "[tid:%u]: Done squashing, switching to running.\n",
				tid);

			renameStatus[tid] = Running;
			return false;
		}
	}

	if (renameStatus[tid] == SerializeStall) {
		// Stall ends once the ROB is free.
		DPRINTF(Rename, "[tid:%u]: Done with serialize stall, switching to "
			"unblocking.\n", tid);

		DynInstPtr serial_inst = serializeInst[tid];

		renameStatus[tid] = Unblocking;

		unblock(tid);

		DPRINTF(Rename, "[tid:%u]: Processing instruction [%lli] with "
			"PC %s.\n", tid, serial_inst->seqNum, serial_inst->pcState());

		// Put instruction into queue here.
		serial_inst->clearSerializeBefore();

		if (!skidBuffer[tid].empty()) {
			skidBuffer[tid].push_front(serial_inst);
		}
		else {
			insts[tid].push_front(serial_inst);
		}

		DPRINTF(Rename, "[tid:%u]: Instruction must be processed by rename."
			" Adding to front of list.\n", tid);

		serializeInst[tid] = NULL;

		return true;
	}

	// If we've reached this point, we have not gotten any signals that
	// cause rename to change its status.  Rename remains the same as before.
	return false;
}

template<class Impl>
void
DefaultRename<Impl>::serializeAfter(InstQueue &inst_list, ThreadID tid)
{
	if (inst_list.empty()) {
		// Mark a bit to say that I must serialize on the next instruction.
		serializeOnNextInst[tid] = true;
		return;
	}

	// Set the next instruction as serializing.
	inst_list.front()->setSerializeBefore();
}

template <class Impl>
inline void
DefaultRename<Impl>::incrFullStat(const FullSource &source)
{
	switch (source) {
	case ROB:
		++renameROBFullEvents;
		break;
	case IQ:
		++renameIQFullEvents;
		break;
	case LQ:
		++renameLQFullEvents;
		break;
	case SQ:
		++renameSQFullEvents;
		break;
	default:
		panic("Rename full stall stat should be incremented for a reason!");
		break;
	}
}

template <class Impl>
void
DefaultRename<Impl>::dumpHistory()
{
	typename std::list<RenameHistory>::iterator buf_it;

	for (ThreadID tid = 0; tid < numThreads; tid++) {

		buf_it = historyBuffer[tid].begin();

		while (buf_it != historyBuffer[tid].end()) {
			cprintf("Seq num: %i\nArch reg[%s]: %i New phys reg:"
				" %i[%s] Old phys reg: %i[%s]\n",
				(*buf_it).instSeqNum,
				(*buf_it).archReg.className(),
				(*buf_it).archReg.index(),
				(*buf_it).newPhysReg->index(),
				(*buf_it).newPhysReg->className(),
				(*buf_it).prevPhysReg->index(),
				(*buf_it).prevPhysReg->className());

			buf_it++;
		}
	}
}

#endif//__CPU_O3_RENAME_IMPL_HH__

