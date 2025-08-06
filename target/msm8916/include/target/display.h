/* Copyright (c) 2013-2015, The Linux Foundation. All rights reserved. */
#ifndef _TARGET_MSM8916_DISPLAY_H
#define _TARGET_MSM8916_DISPLAY_H

/*---------------------------------------------------------------------------*/
/* HEADER files                                                              */
/*---------------------------------------------------------------------------*/
#include <display_resource.h>

/*---------------------------------------------------------------------------*/
/* Target Physical configuration                                             */
/*---------------------------------------------------------------------------*/

static const uint32_t panel_strength_ctrl[] = {
  0xff, 0x06
};

static const char panel_bist_ctrl[] = {
  0x00, 0x00, 0xb1, 0xff, 0x00, 0x00
};

extern uint32_t panel_regulator_settings[7];

static const uint32_t dcdc_regulator_settings[] = {
  0x03, 0x08, 0x07, 0x00, 0x20, 0x07, 0x01
};

static const uint32_t ldo_regulator_settings[] = {
  0x00, 0x01, 0x01, 0x00, 0x20, 0x07, 0x00
};

static const char panel_lane_config[] = {
  0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x97,
  0x01, 0xc0, 0x00, 0x00, 0x05, 0x00, 0x00, 0x01, 0x97,
  0x01, 0xc0, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x01, 0x97,
  0x01, 0xc0, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x01, 0x97,
  0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff
};

static const uint32_t panel_physical_ctrl[] = {
  0x5f, 0x00, 0x00, 0x10
};

/*---------------------------------------------------------------------------*/
/* Other Configuration                                                       */
/*---------------------------------------------------------------------------*/
#define DISPLAY_CMDLINE_PREFIX " mdss_mdp.panel="

#define MIPI_FB_ADDR 0x83200000

#define MIPI_HSYNC_PULSE_WIDTH       12
#define MIPI_HSYNC_BACK_PORCH_DCLK   32
#define MIPI_HSYNC_FRONT_PORCH_DCLK  144

#define MIPI_VSYNC_PULSE_WIDTH       4
#define MIPI_VSYNC_BACK_PORCH_LINES  3
#define MIPI_VSYNC_FRONT_PORCH_LINES 9

enum qrd_subtype
{
	HW_PLATFORM_SUBTYPE_DEFAULT = 0,
	HW_PLATFORM_SUBTYPE_CDP_1 = 1,
	HW_PLATFORM_SUBTYPE_CDP_2 = 2,
	HW_PLATFORM_SUBTYPE_MTP_3 = 3,
	HW_PLATFORM_SUBTYPE_SKUH = 4,
	HW_PLATFORM_SUBTYPE_SKUI = 5, /* msm8916 */
	HW_PLATFORM_SUBTYPE_SKUK = 5, /* msm8939 */
	HW_PLATFORM_SUBTYPE_SKUT1 = 0x40, /* msm8916 */
};


enum {
	TMOTM9605A_QHD_VID_PANEL,
	UNKNOWN_PANEL
};

/*---------------------------------------------------------------------------*/
/* Functions		                                                     */
/*---------------------------------------------------------------------------*/
int target_display_pre_on(void);
int target_display_pre_off(void);
int target_display_post_on(void);
int target_display_post_off(void);
int target_cont_splash_screen(void);
int target_display_get_base_offset(uint32_t base);
void target_force_cont_splash_disable(uint8_t override);
uint8_t target_panel_auto_detect_enabled(void);
uint32_t oem_panel_max_auto_detect_panels(void);

void target_set_switch_gpio(int enable_dsi2HdmiBridge);

#endif
