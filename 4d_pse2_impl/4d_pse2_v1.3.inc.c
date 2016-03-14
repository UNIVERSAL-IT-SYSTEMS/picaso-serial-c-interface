#ifndef __4D_PSE2_V1_3_INC_C__
#define __4D_PSE2_V1_3_INC_C__

#include "4d_pse2.h"

// cmd reference: http://www.4dsystems.com.au/productpages/PICASO/downloads/PICASO_serialcmdmanual_R_1_18.pdf


#define __N(func, cmd_id) \
__(status_t) __(func) (void) { \
	L4D_PSE2_PUTWORD(cmd_id); \
	return L4D_PSE2_GETCHAR(); \
}

#define __S(func, cmd_id, ...) \
__(status_t) __(func) ( __ARGS(__VA_ARGS__) ) { \
	L4D_PSE2_PUTWORD(cmd_id); \
	__CMDS( VA_NARGS(__VA_ARGS__) ) \
	return L4D_PSE2_GETCHAR(); \
}

#define __R_1W(func, cmd_id, ...) \
__(result_t) __(func) ( __ARGS(__VA_ARGS__) ) { \
	L4D_PSE2_PUTWORD(cmd_id); \
	__CMDS( VA_NARGS(__VA_ARGS__) ) \
	__(result_t) ret; \
	ret.status = L4D_PSE2_GETCHAR(); \
	if (ret.status == L4D_PSE2_ACK) \
	    ret.value = L4D_PSE2_GETWORD(); \
	else \
		ret.value = 0; \
	return ret; \
}

// map word calls to byte calls, if no dedicated implementtation
#ifndef L4D_PSE2_PUTWORD
void _l4d_pse2_putword(uint16_t value) {
	L4D_PSE2_PUTCHAR((uint8_t)((value >> 8) & 0xff));
	L4D_PSE2_PUTCHAR((uint8_t)((value >> 0) & 0xff));
}
# define L4D_PSE2_PUTWORD _l4d_pse2_putword
#endif

#ifndef L4D_PSE2_GETWORD
uint16_t _l4d_pse2_getword(void) {
	int16_t a = L4D_PSE2_GETCHAR();
	if (a > 0) {
		int16_t b = L4D_PSE2_GETCHAR();
		if (b > 0) {
			uint8_t a_ = a, b_ = b;
			return (uint16_t)a_ << 8 | b_;
		}
	}
	return 0; // FIXME: return the error some way
}
# define L4D_PSE2_GETWORD _l4d_pse2_getword
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Text and String Commands
//

__S(txt_MoveCursor, 0xFFE9, uint16_t, uint16_t)

__S(txt_PutChar, 0xFFFE, uint8_t)
__S(putCH, 0xFFFE, uint8_t)

__(status_t) __(txt_PutString) (char* str) {
	L4D_PSE2_PUTWORD(0x0018);
	uint16_t i;
	for (i=0; i < 511 && str[i] != '\0'; i++) {
		L4D_PSE2_PUTCHAR(str[i]);
	}
	L4D_PSE2_PUTCHAR('\0');

	uint8_t ack = L4D_PSE2_GETCHAR();
	L4D_PSE2_GETWORD(); // FIXME: return this?
	return ack == L4D_PSE2_ACK;
}
__(status_t) __(putstr) (char* str) { return __(txt_PutString)(str); }

// TODO: txt_CharacterWidth

// TODO: txt_CharacterHeight

__R_1W(txt_FGColour, 0xFFE7, __(colour_t))

__R_1W(txt_BGColour, 0xFFE6, __(colour_t))

__R_1W(txt_FontID, 0xFFE5, uint16_t)
// TODO: alias txt_SetFont

__R_1W(txt_Width, 0xFFE4, uint16_t)

__R_1W(txt_Height, 0xFFE3, uint16_t)

__R_1W(txt_Xgap, 0xFFE2, uint16_t)

__R_1W(txt_Ygap, 0xFFE1, uint16_t)

__R_1W(txt_Bold, 0xFFDE, uint16_t)

__R_1W(txt_Inverse, 0xFFDC, uint16_t)

__R_1W(txt_Italic, 0xFFDD, uint16_t)

__R_1W(txt_Opacity, 0xFFDF, uint16_t)

__R_1W(txt_Underline, 0xFFDF, uint16_t)

__R_1W(txt_Attributes, 0xFFDA, uint16_t)

__R_1W(txt_Wrap, 0xFFD9, uint16_t)


///////////////////////////////////////////////////////////////////////////////
//
// Graphics Commands
//

__N(gfx_Cls, 0xFFCD)

__S(gfx_ChangeColour, 0xFFB4, __(colour_t), __(colour_t))

__S(gfx_Circle, 0xFFC3, uint16_t, uint16_t, uint16_t, __(colour_t))

__S(gfx_CircleFilled, 0xFFC2, uint16_t, uint16_t, uint16_t, __(colour_t))

__S(gfx_Line, 0xFFC8, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t))

__S(gfx_Rectangle, 0xFFC5, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t))

__S(gfx_RectangleFilled, 0xFFC4, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t))

// TODO: gfx_Polyline

// TODO: gfx_Polygon

// TODO: gfx_PolygonFilled

__S(gfx_Triangle, 0xFFBF, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t))

__S(gfx_TriangleFilled, 0xFFA9, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t))

// TODO: gfx_Orbit

__S(gfx_PutPixel, 0xFFC1, uint16_t, uint16_t, __(colour_t))


// TODO: gfx_GetPixel

__S(gfx_MoveTo, 0xFFCC, uint16_t, uint16_t)

__S(gfx_LineTo, 0xFFCA, uint16_t, uint16_t)

__S(gfx_Clipping, 0xFFA2, uint16_t)

__S(gfx_ClipWindow, 0xFFB5, uint16_t, uint16_t, uint16_t, uint16_t)

__N(gfx_SetClipRegion, 0xFFB3)

__S(gfx_Ellipse, 0xFFB2, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t))

__S(gfx_EllipseFilled, 0xFFB1, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t))

// TODO: gfx_Button

__S(gfx_Panel, 0xFFAF, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t))

__S(gfx_Slider, 0xFFAE, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, __(colour_t), uint16_t, int16_t)

__S(gfx_ScreenCopyPaste, 0xFFAD, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t)

__R_1W(gfx_BevelShadow, 0xFF98, uint16_t)

__R_1W(gfx_BevelWidth, 0xFF99, uint16_t)

__R_1W(gfx_BGcolour, 0xFFA4, __(colour_t))

__R_1W(gfx_OutlineColour, 0xFF9D, __(colour_t))

__R_1W(gfx_Contrast, 0xFF9C, uint16_t)

__R_1W(gfx_FrameDelay, 0xFF9F, uint16_t)

__R_1W(gfx_LinePattern, 0xFF9B, uint16_t)

__R_1W(gfx_ScreenMode, 0xFF9E, __(orientation_t))

__R_1W(gfx_Transparency, 0xFFA0, uint16_t)

__R_1W(gfx_TransparentColour, 0xFFA1, __(colour_t))

__S(gfx_Set, 0xFFCE, uint16_t, uint16_t)

// TODO: gfx_Get


///////////////////////////////////////////////////////////////////////////////
//
// Media Commands (SD/SDHC Memory Cards)
//

// TODO



///////////////////////////////////////////////////////////////////////////////
//
// Serial (UART) Communications Commands
//

__S(setbaudWait, 0x0026, __(baud_rate_t))



///////////////////////////////////////////////////////////////////////////////
//
// Timer Commands
//

// TODO: sys_Sleep


///////////////////////////////////////////////////////////////////////////////
//
// FAT16 File Commands
//

// TODO



///////////////////////////////////////////////////////////////////////////////
//
// Sound Control Commands
//

// TODO


///////////////////////////////////////////////////////////////////////////////
//
// Touch Screen Commands
//

__S(touch_DetectRegion, 0xFF39, uint16_t, uint16_t, uint16_t, uint16_t)
__S(touch_Set, 0xFF38, __(touch_mode_t))
__R_1W(touch_Get, 0xFF37, __(touch_status_t))

///////////////////////////////////////////////////////////////////////////////
//
// Image Control Commands
//

// TODO


///////////////////////////////////////////////////////////////////////////////
//
// System Commands
//

// TODO


///////////////////////////////////////////////////////////////////////////////
//
// I/O Commands
//

__R_1W(pin_HI, 0xFFD6, uint16_t)
__R_1W(pin_LO, 0xFFD5, uint16_t)

// TODO

#endif
