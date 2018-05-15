/** Copyright 2018 Enzien Audio, Ltd. All Rights Reserved. */

#ifndef _HEAVY_CONTEXT_BASIC_DELAY_HPP_
#define _HEAVY_CONTEXT_BASIC_DELAY_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalTabwrite.h"
#include "HvTable.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
#include "HvControlTabhead.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvSignalTabread.h"
#include "HvControlCast.h"

class Heavy_basic_delay : public HeavyContext {

 public:
  Heavy_basic_delay(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_basic_delay();

  const char *getName() override { return "basic_delay"; }
  int getNumInputChannels() override { return 1; }
  int getNumOutputChannels() override { return 1; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void hTable_6CoGk3yY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oSgsexmf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Uq2EiYQb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Bl4o1LkK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lN2UHA7j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_rOi8jhrd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2G5ZjPgC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cm7yjnRq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_c7aOyXYl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_IJESVuyX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eswg43zX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_a5DU98sS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_35Bm783X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MgeFSGJd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CTWECGcG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VupCuyc8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_yyI4EOGy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GbbJL2XG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Y5iV0HVV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e6QoJ7Gt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_yGq0p1mu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7GhGJRS3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_07RDwnnP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VT1jOqSm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EatBIXid_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Dkt1cVsV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uMg2whJg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rAl0Rhxg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_19D3MvuX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_AEY0LqAn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JuPXQLu2_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabread sTabread_a5DU98sS;
  SignalTabwrite sTabwrite_JuRUeT6j;
  HvTable hTable_6CoGk3yY;
  ControlDelay cDelay_rOi8jhrd;
  ControlBinop cBinop_c7aOyXYl;
  ControlDelay cDelay_IJESVuyX;
  ControlBinop cBinop_eswg43zX;
  ControlDelay cDelay_35Bm783X;
  ControlBinop cBinop_CTWECGcG;
  ControlVar cVar_GbbJL2XG;
  ControlDelay cDelay_Y5iV0HVV;
  ControlBinop cBinop_e6QoJ7Gt;
  ControlTabhead cTabhead_yGq0p1mu;
  ControlBinop cBinop_7GhGJRS3;
  ControlBinop cBinop_EatBIXid;
  ControlBinop cBinop_Dkt1cVsV;
  ControlBinop cBinop_uMg2whJg;
};

#endif // _HEAVY_CONTEXT_BASIC_DELAY_HPP_
