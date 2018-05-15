/** Copyright 2018 Enzien Audio, Ltd. All Rights Reserved. */

#include "Heavy_basic_delay.hpp"

#define Context(_c) reinterpret_cast<Heavy_basic_delay *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_basic_delay_new(double sampleRate) {
    return new Heavy_basic_delay(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_basic_delay_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_basic_delay(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_basic_delay::Heavy_basic_delay(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabread_init(&sTabread_a5DU98sS, &hTable_6CoGk3yY, true);
  numBytes += sTabwrite_init(&sTabwrite_JuRUeT6j, &hTable_6CoGk3yY);
  numBytes += hTable_init(&hTable_6CoGk3yY, 256);
  numBytes += cDelay_init(this, &cDelay_rOi8jhrd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_IJESVuyX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_35Bm783X, 0.0f);
  numBytes += cBinop_init(&cBinop_CTWECGcG, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_GbbJL2XG, "del-delay");
  numBytes += cDelay_init(this, &cDelay_Y5iV0HVV, 500.0f);
  numBytes += cBinop_init(&cBinop_e6QoJ7Gt, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_yGq0p1mu, &hTable_6CoGk3yY);
  numBytes += cBinop_init(&cBinop_EatBIXid, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Dkt1cVsV, 500.0f); // __mul
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_basic_delay::~Heavy_basic_delay() {
  hTable_free(&hTable_6CoGk3yY);
}

HvTable *Heavy_basic_delay::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x52B9CED0: return &hTable_6CoGk3yY; // del-delay
    default: return nullptr;
  }
}

void Heavy_basic_delay::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JuPXQLu2_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_basic_delay::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_basic_delay::hTable_6CoGk3yY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cm7yjnRq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IJESVuyX, 2, m, &cDelay_IJESVuyX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2G5ZjPgC_sendMessage);
}

void Heavy_basic_delay::cMsg_oSgsexmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Uq2EiYQb_sendMessage);
}

void Heavy_basic_delay::cSystem_Uq2EiYQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_c7aOyXYl_sendMessage);
}

void Heavy_basic_delay::cMsg_Bl4o1LkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6CoGk3yY, 0, m, &hTable_6CoGk3yY_sendMessage);
}

void Heavy_basic_delay::cMsg_lN2UHA7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6CoGk3yY, 0, m, &hTable_6CoGk3yY_sendMessage);
}

void Heavy_basic_delay::cDelay_rOi8jhrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rOi8jhrd, m);
  cMsg_Bl4o1LkK_sendMessage(_c, 0, m);
}

void Heavy_basic_delay::cCast_2G5ZjPgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IJESVuyX, 0, m, &cDelay_IJESVuyX_sendMessage);
}

void Heavy_basic_delay::cMsg_cm7yjnRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rOi8jhrd, 2, m, &cDelay_rOi8jhrd_sendMessage);
}

void Heavy_basic_delay::cBinop_c7aOyXYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_eswg43zX_sendMessage);
}

void Heavy_basic_delay::cDelay_IJESVuyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IJESVuyX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rOi8jhrd, 0, m, &cDelay_rOi8jhrd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IJESVuyX, 0, m, &cDelay_IJESVuyX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JuRUeT6j, 1, m, NULL);
}

void Heavy_basic_delay::cBinop_eswg43zX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lN2UHA7j_sendMessage(_c, 0, m);
}

void Heavy_basic_delay::sTabread_a5DU98sS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_e6QoJ7Gt, HV_BINOP_SUBTRACT, 0, m, &cBinop_e6QoJ7Gt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_basic_delay::cDelay_35Bm783X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_35Bm783X, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_a5DU98sS, 0, m, &sTabread_a5DU98sS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_35Bm783X, 0, m, &cDelay_35Bm783X_sendMessage);
}

void Heavy_basic_delay::cCast_MgeFSGJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y5iV0HVV, 0, m, &cDelay_Y5iV0HVV_sendMessage);
}

void Heavy_basic_delay::cBinop_CTWECGcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VT1jOqSm_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_a5DU98sS, 0, m, &sTabread_a5DU98sS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MgeFSGJd_sendMessage);
}

void Heavy_basic_delay::cMsg_VupCuyc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_EatBIXid, HV_BINOP_MAX, 1, m, &cBinop_EatBIXid_sendMessage);
}

void Heavy_basic_delay::cSystem_yyI4EOGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e6QoJ7Gt, HV_BINOP_SUBTRACT, 1, m, &cBinop_e6QoJ7Gt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_35Bm783X, 2, m, &cDelay_35Bm783X_sendMessage);
}

void Heavy_basic_delay::cVar_GbbJL2XG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_07RDwnnP_sendMessage(_c, 0, m);
}

void Heavy_basic_delay::cDelay_Y5iV0HVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Y5iV0HVV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_35Bm783X, 0, m, &cDelay_35Bm783X_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_a5DU98sS, 0, m, &sTabread_a5DU98sS_sendMessage);
}

void Heavy_basic_delay::cBinop_e6QoJ7Gt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7GhGJRS3_sendMessage);
}

void Heavy_basic_delay::cTabhead_yGq0p1mu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CTWECGcG, HV_BINOP_SUBTRACT, 0, m, &cBinop_CTWECGcG_sendMessage);
}

void Heavy_basic_delay::cBinop_7GhGJRS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y5iV0HVV, 2, m, &cDelay_Y5iV0HVV_sendMessage);
}

void Heavy_basic_delay::cMsg_07RDwnnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yyI4EOGy_sendMessage);
}

void Heavy_basic_delay::cMsg_VT1jOqSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y5iV0HVV, 0, m, &cDelay_Y5iV0HVV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_35Bm783X, 0, m, &cDelay_35Bm783X_sendMessage);
}

void Heavy_basic_delay::cBinop_EatBIXid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CTWECGcG, HV_BINOP_SUBTRACT, 1, m, &cBinop_CTWECGcG_sendMessage);
}

void Heavy_basic_delay::cBinop_Dkt1cVsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EatBIXid, HV_BINOP_MAX, 0, m, &cBinop_EatBIXid_sendMessage);
}

void Heavy_basic_delay::cBinop_uMg2whJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dkt1cVsV, HV_BINOP_MULTIPLY, 0, m, &cBinop_Dkt1cVsV_sendMessage);
}

void Heavy_basic_delay::cCast_rAl0Rhxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GbbJL2XG, 0, m, &cVar_GbbJL2XG_sendMessage);
  cMsg_19D3MvuX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yGq0p1mu, 0, m, &cTabhead_yGq0p1mu_sendMessage);
}

void Heavy_basic_delay::cMsg_19D3MvuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AEY0LqAn_sendMessage);
}

void Heavy_basic_delay::cSystem_AEY0LqAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uMg2whJg_sendMessage);
}

void Heavy_basic_delay::cReceive_JuPXQLu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oSgsexmf_sendMessage(_c, 0, m);
  cMsg_VupCuyc8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GbbJL2XG, 0, m, &cVar_GbbJL2XG_sendMessage);
  cMsg_19D3MvuX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yGq0p1mu, 0, m, &cTabhead_yGq0p1mu_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_basic_delay::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1;

  // input and output vars
  hv_bufferf_t O0;
  hv_bufferf_t I0;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));

    // zero output buffers
    __hv_zero_f(VOf(O0));

    // process all signal functions
    __hv_tabread_f(&sTabread_a5DU98sS, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(I0), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_JuRUeT6j, VIf(Bf1));
    __hv_add_f(VIf(Bf0), VIf(I0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_basic_delay::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 1 channel(s)
  float **const bIn = &inputBuffers;

  // define the heavy output buffer for 1 channel(s)
  float **const bOut = &outputBuffers;

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_basic_delay::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 1 channel(s), uninterleave
  float *const bIn = inputBuffers;

  // define the heavy output buffer for 1 channel(s)
  float *const bOut = outputBuffers;

  int n = processInline(bIn, bOut, n4);

  

  return n;
}
