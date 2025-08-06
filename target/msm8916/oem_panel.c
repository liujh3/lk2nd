/* Copyright (c) 2013-2015, The Linux Foundation. All rights reserved. */

#include <debug.h>
#include <err.h>
#include <smem.h>
#include <msm_panel.h>
#include <board.h>
#include <mipi_dsi.h>
#include <target/display.h>
#include <mipi_dsi_i2c.h>
#include <platform/timer.h>

#include "include/panel.h"
#include "panel_display.h"
#include <blsp_qup.h>

/*---------------------------------------------------------------------------*/
/* GCDB Panel Database                                                       */
/*---------------------------------------------------------------------------*/
#include "include/lk_panel_tmotm9605a_qhd_vid.h"

/*---------------------------------------------------------------------------*/
/* static panel selection variable                                           */
/*---------------------------------------------------------------------------*/
static uint32_t panel_id = TMOTM9605A_QHD_VID_PANEL;

uint32_t panel_regulator_settings[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*
 * The list of panels that are supported on this target.
 * Any panel in this list can be selected using fastboot oem command.
 */
static struct panel_list supp_panels[] = {
	{"tmotm9605a_qhd_vid", TMOTM9605A_QHD_VID_PANEL},
};

static uint32_t panel_id;

int oem_panel_rotation(void)
{
	return NO_ERROR;
}

int oem_panel_on(void)
{
	/*
	 *OEM can keep their panel specific on instructions in this
	 *function
	 */

	return NO_ERROR;
}

int oem_panel_off(void)
{
	/* OEM can keep their panel specific off instructions
	 * in this function
	 */
	return NO_ERROR;
}

static int init_panel_data(struct panel_struct *panelstruct,
			struct msm_panel_info *pinfo,
			struct mdss_dsi_phy_ctrl *phy_db)
{
	int pan_type = PANEL_TYPE_DSI;

	switch (panel_id) {
	case TMOTM9605A_QHD_VID_PANEL:
		panelstruct->paneldata = &tmotm9605a_qhd_vid_panel_data;
		panelstruct->panelres = &tmotm9605a_qhd_vid_panel_res;
		panelstruct->color = &tmotm9605a_qhd_vid_color;
		panelstruct->videopanel = &tmotm9605a_qhd_vid_video_panel;
		panelstruct->commandpanel = &tmotm9605a_qhd_vid_command_panel;
		panelstruct->state = &tmotm9605a_qhd_vid_state;
		panelstruct->laneconfig = &tmotm9605a_qhd_vid_lane_config;
		panelstruct->paneltiminginfo = &tmotm9605a_qhd_vid_timing_info;
		panelstruct->panelresetseq = &tmotm9605a_qhd_vid_reset_seq;
		panelstruct->backlightinfo = &tmotm9605a_qhd_vid_backlight;
		pinfo->mipi.panel_on_cmds = tmotm9605a_qhd_vid_on_command;
		pinfo->mipi.panel_off_cmds = tmotm9605a_qhd_vid_off_command;
		pinfo->mipi.num_of_panel_on_cmds = ARRAY_SIZE(tmotm9605a_qhd_vid_on_command);
		pinfo->mipi.num_of_panel_off_cmds = ARRAY_SIZE(tmotm9605a_qhd_vid_off_command);
		memcpy(phy_db->timing, tmotm9605a_qhd_vid_timings, TIMING_SIZE);
		phy_db->regulator_mode = DSI_PHY_REGULATOR_DCDC_MODE;
		break;
	case UNKNOWN_PANEL:
	default:
		memset(panelstruct, 0, sizeof(struct panel_struct));
		memset(pinfo->mipi.panel_on_cmds, 0,
					sizeof(struct mipi_dsi_cmd));
		pinfo->mipi.num_of_panel_on_cmds = 0;
		memset(pinfo->mipi.panel_off_cmds, 0,
					sizeof(struct mipi_dsi_cmd));
		pinfo->mipi.num_of_panel_off_cmds = 0;
		memset(phy_db->timing, 0, TIMING_SIZE);
		pan_type = PANEL_TYPE_UNKNOWN;
		break;
	}
	return pan_type;
}

uint32_t oem_panel_max_auto_detect_panels(void)
{
        return 0;
}

int oem_panel_select(const char *panel_name, struct panel_struct *panelstruct,
			struct msm_panel_info *pinfo,
			struct mdss_dsi_phy_ctrl *phy_db)
{
	dprintf(INFO, "Force selecting tmotm9605a_qhd_vid panel.\n");

	panel_id = TMOTM9605A_QHD_VID_PANEL;

	memcpy(panel_regulator_settings,
				dcdc_regulator_settings, REGULATOR_SIZE);

	pinfo->pipe_type = MDSS_MDP_PIPE_TYPE_RGB;
	return init_panel_data(panelstruct, pinfo, phy_db);
}
