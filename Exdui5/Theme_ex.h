#pragma once
#include "help_ex.h"
#include "Resource_ex.h"
#include "Format_ex.h"

#define EPDF_PNGBITS 1

struct theme_s
{
	void* tableFiles_;
	int loadCount_;
	int crcTheme_;
	void* tableClass_;
	void* aryColors_;
};

struct colors_s
{
	int BACKGROUND;
	int BORDER;
	int TEXT_NORMAL;
	int TEXT_HOVER;
	int TEXT_DOWN;
	int TEXT_FOCUS;
	int TEXT_CHECKED;
	int TEXT_SELECT;
	int TEXT_HOT;
	int TEXT_VISTED;
	int TEXT_SHADOW;
};

bool _theme_unpack(void* lpData, size_t dwDataLen, void* lpKey, size_t dwKeyLen, std::vector<int>* atomFiles, std::vector<void*>* lpFiles, std::vector<UCHAR>* dwFileProps);
int _theme_fillitems(void* lpContent, std::vector<int>* artItems1, std::vector<size_t>* artItems2);
bool _theme_fillclasses(void* pTableFiles, void* pTableClass, std::vector<int> atomFiles, std::vector<void*> lpFiles, std::vector<UCHAR> dwFileProps, void* aryCorlors);
void _theme_freeclass(void* pClass);
void* Ex_ThemeLoadFromMemory(void* lpData, size_t dwDataLen, void* lpKey, size_t dwKeyLen, bool bDefault);
void* Ex_ThemeLoadFromFile(void* lptszFile, void* lpKey, size_t dwKeyLen, bool bDefault);
bool Ex_ThemeDrawControlEx(void* hTheme, ExHandle hCanvas, float dstLeft, float dstTop, float dstRight, float dstBottom,
	int atomClass, int atomSrcRect, int atomBackgroundRepeat, int atomBackgroundPositon, int atomBackgroundGrid, int atomBackgroundFlags, int dwAlpha);
bool Ex_ThemeDrawControl(void* hTheme, ExHandle hCanvas, float dstLeft, float dstTop, float dstRight, float dstBottom,
	int atomClass, int atomSrcRect, int dwAlpha);
void* Ex_ThemeGetValuePtr(void* hTheme, int atomClass, int atomProp);
int Ex_ThemeGetColor(void* hTheme, int nIndex);
bool Ex_ThemeFree(void* hTheme);