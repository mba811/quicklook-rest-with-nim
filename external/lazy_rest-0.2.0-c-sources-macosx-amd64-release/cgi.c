/* Generated by Nimrod Compiler v0.9.6 */
/*   (c) 2014 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <string.h>
typedef struct tstringtable127812 tstringtable127812;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct tkeyvaluepairseq127810 tkeyvaluepairseq127810;
typedef struct tkeyvaluepair127808 tkeyvaluepair127808;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_NIMCALL_PTR(void, TY2689) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, TY2694) (void* p);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY2689 marker;
TY2694 deepcopy;
};
struct  TNimObject  {
TNimType* m_type;
};
struct tkeyvaluepair127808 {
NimStringDesc* Field0;
NimStringDesc* Field1;
};
struct  tstringtable127812  {
  TNimObject Sup;
NI Counter;
tkeyvaluepairseq127810* Data;
NU8 Mode;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct tkeyvaluepairseq127810 {
  TGenericSeq Sup;
  tkeyvaluepair127808 data[SEQ_DECL_SIZE];
};
N_NIMCALL(NimStringDesc*, rawNewString)(NI space);
N_NIMCALL(NimStringDesc*, rawNewString)(NI cap);
static N_INLINE(void, addxmlchar_199266)(NimStringDesc** dest, NIM_CHAR c);
static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src);
N_NIMCALL(NimStringDesc*, resizeString)(NimStringDesc* dest, NI addlen);
N_NIMCALL(NimStringDesc*, addChar)(NimStringDesc* s, NIM_CHAR c);
STRING_LITERAL(TMP828, "&amp;", 5);
STRING_LITERAL(TMP829, "&lt;", 4);
STRING_LITERAL(TMP830, "&gt;", 4);
STRING_LITERAL(TMP831, "&quot;", 6);
tstringtable127812* gcookies_200161;

static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src) {
	memcpy(((NCSTRING) (&(*dest).data[((*dest).Sup.len)- 0])), ((NCSTRING) ((*src).data)), (NI64)((*src).Sup.len + 1));
	(*dest).Sup.len += (*src).Sup.len;
}

static N_INLINE(void, addxmlchar_199266)(NimStringDesc** dest, NIM_CHAR c) {
	switch (((NU8)(c))) {
	case 38:
	{
		(*dest) = resizeString((*dest), 5);
appendString((*dest), ((NimStringDesc*) &TMP828));
	}
	break;
	case 60:
	{
		(*dest) = resizeString((*dest), 4);
appendString((*dest), ((NimStringDesc*) &TMP829));
	}
	break;
	case 62:
	{
		(*dest) = resizeString((*dest), 4);
appendString((*dest), ((NimStringDesc*) &TMP830));
	}
	break;
	case 34:
	{
		(*dest) = resizeString((*dest), 6);
appendString((*dest), ((NimStringDesc*) &TMP831));
	}
	break;
	default:
	{
		(*dest) = addChar((*dest), c);
	}
	break;
	}
}

N_NIMCALL(NimStringDesc*, xmlencode_199277)(NimStringDesc* s) {
	NimStringDesc* result;
	result = 0;
	result = rawNewString((NI64)(s->Sup.len + (NI)((NU64)(s->Sup.len) >> (NU64)(2))));
	{
		NI i_199291;
		NI HEX3Atmp_199294;
		NI res_199297;
		i_199291 = 0;
		HEX3Atmp_199294 = 0;
		HEX3Atmp_199294 = (NI64)(s->Sup.len - 1);
		res_199297 = 0;
		{
			while (1) {
				if (!(res_199297 <= HEX3Atmp_199294)) goto LA3;
				i_199291 = res_199297;
				addxmlchar_199266(&result, s->data[i_199291]);
				res_199297 += 1;
			} LA3: ;
		}
	}
	return result;
}
N_NOINLINE(void, HEX00_cgiInit)(void) {
}

N_NOINLINE(void, HEX00_cgiDatInit)(void) {
}

