/* Generated by Nimrod Compiler v0.9.6 */
/*   (c) 2014 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 64
#include "nimbase.h"
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
static N_INLINE(NI, HEX21HEX26_125017)(NI h, NI val);
static N_INLINE(NI, HEX21HEX24_125046)(NI h);

static N_INLINE(NI, HEX21HEX26_125017)(NI h, NI val) {
	NI result;
	result = 0;
	result = (NI)((NU64)(h) + (NU64)(val));
	result = (NI)((NU64)(result) + (NU64)((NI)((NU64)(result) << (NU64)(10))));
	result = (NI)(result ^ (NI)((NU64)(result) >> (NU64)(6)));
	return result;
}

static N_INLINE(NI, HEX21HEX24_125046)(NI h) {
	NI result;
	result = 0;
	result = (NI)((NU64)(h) + (NU64)((NI)((NU64)(h) << (NU64)(3))));
	result = (NI)(result ^ (NI)((NU64)(result) >> (NU64)(11)));
	result = (NI)((NU64)(result) + (NU64)((NI)((NU64)(result) << (NU64)(15))));
	return result;
}

N_NIMCALL(NI, hash_125842)(NimStringDesc* x) {
	NI result;
	NI h;
	result = 0;
	h = 0;
	{
		NI i_125857;
		NI HEX3Atmp_125868;
		NI res_125871;
		i_125857 = 0;
		HEX3Atmp_125868 = 0;
		HEX3Atmp_125868 = (NI64)(x->Sup.len - 1);
		res_125871 = 0;
		{
			while (1) {
				if (!(res_125871 <= HEX3Atmp_125868)) goto LA3;
				i_125857 = res_125871;
				h = HEX21HEX26_125017(h, ((NI) (((NU8)(x->data[i_125857])))));
				res_125871 += 1;
			} LA3: ;
		}
	}
	result = HEX21HEX24_125046(h);
	return result;
}

N_NIMCALL(NI, hashignorecase_125980)(NimStringDesc* x) {
	NI result;
	NI h;
	result = 0;
	h = 0;
	{
		NI i_125995;
		NI HEX3Atmp_126048;
		NI res_126051;
		i_125995 = 0;
		HEX3Atmp_126048 = 0;
		HEX3Atmp_126048 = (NI64)(x->Sup.len - 1);
		res_126051 = 0;
		{
			while (1) {
				NIM_CHAR c;
				if (!(res_126051 <= HEX3Atmp_126048)) goto LA3;
				i_125995 = res_126051;
				c = x->data[i_125995];
				{
					if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA6;
					c = ((NIM_CHAR) (((NI) ((NI64)(((NI) (((NU8)(c)))) + 32)))));
				}
				LA6: ;
				h = HEX21HEX26_125017(h, ((NI) (((NU8)(c)))));
				res_126051 += 1;
			} LA3: ;
		}
	}
	result = HEX21HEX24_125046(h);
	return result;
}

N_NIMCALL(NI, hashignorestyle_125888)(NimStringDesc* x) {
	NI result;
	NI h;
	result = 0;
	h = 0;
	{
		NI i_125903;
		NI HEX3Atmp_125957;
		NI res_125960;
		i_125903 = 0;
		HEX3Atmp_125957 = 0;
		HEX3Atmp_125957 = (NI64)(x->Sup.len - 1);
		res_125960 = 0;
		{
			while (1) {
				if (!(res_125960 <= HEX3Atmp_125957)) goto LA3;
				i_125903 = res_125960;
				{
					NIM_CHAR c;
					c = x->data[i_125903];
					{
						if (!((NU8)(c) == (NU8)(95))) goto LA7;
						goto LA4;
					}
					LA7: ;
					{
						if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA11;
						c = ((NIM_CHAR) (((NI) ((NI64)(((NI) (((NU8)(c)))) + 32)))));
					}
					LA11: ;
					h = HEX21HEX26_125017(h, ((NI) (((NU8)(c)))));
				} LA4: ;
				res_125960 += 1;
			} LA3: ;
		}
	}
	result = HEX21HEX24_125046(h);
	return result;
}
N_NOINLINE(void, HEX00_hashesInit)(void) {
}

N_NOINLINE(void, HEX00_hashesDatInit)(void) {
}

