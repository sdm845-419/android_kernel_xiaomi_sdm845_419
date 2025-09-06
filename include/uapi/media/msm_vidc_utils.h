/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef __MSM_VIDC_UTILS_H__
#define __MSM_VIDC_UTILS_H__

#include <linux/types.h>

#if defined(CONFIG_ARCH_SDM845)
#define VENUS_USES_LEGACY_MISR_INFO
#endif

/* Color formats */
#define MSM_VIDC_EXTRADATA_NONE 0x00000000
#define MSM_VIDC_HAL_INTERLACE_COLOR_FORMAT_NV12	0x2
#define MSM_VIDC_HAL_INTERLACE_COLOR_FORMAT_NV12_UBWC	0x8002
#define MSM_VIDC_4x_1 0x1
#define MSM_VIDC_EXTRADATA_FRAME_QP_ADV 0x1
#define MSM_VIDC_EXTRADATA_INTERLACE_VIDEO 0x00000002

struct msm_vidc_extradata_header {
	unsigned int size;
	unsigned int:32; /** Keeping binary compatibility */
	unsigned int:32; /* with firmware and OpenMAX IL **/
	unsigned int type; /* msm_vidc_extradata_type */
	unsigned int data_size;
	unsigned char data[1];
};

/* msm_vidc_interlace_type */
#define MSM_VIDC_INTERLACE_FRAME_PROGRESSIVE 0x01
#define MSM_VIDC_INTERLACE_INTERLEAVE_FRAME_TOPFIELDFIRST 0x02
#define MSM_VIDC_INTERLACE_INTERLEAVE_FRAME_BOTTOMFIELDFIRST 0x04
#define MSM_VIDC_INTERLACE_FRAME_TOPFIELDFIRST 0x08
#define MSM_VIDC_INTERLACE_FRAME_BOTTOMFIELDFIRST 0x10
#define MSM_VIDC_INTERLACE_FRAME_MBAFF 0x20

struct msm_vidc_interlace_payload {
	unsigned int format; /* Interlace format */
	unsigned int color_format;
};

#define MSM_VIDC_EXTRADATA_FRAME_RATE 0x00000007
struct msm_vidc_framerate_payload {
	unsigned int frame_rate;; /*In Q16 format */
};

#define MSM_VIDC_EXTRADATA_TIMESTAMP 0x00000005
struct msm_vidc_ts_payload {
	unsigned int timestamp_lo;
	unsigned int timestamp_hi;
};

#define MSM_VIDC_EXTRADATA_NUM_CONCEALED_MB 0x7F100001
struct msm_vidc_concealmb_payload {
	unsigned int num_mbs;
};


#define MSM_VIDC_FRAME_RECONSTRUCTION_INCORRECT 0x0
#define MSM_VIDC_FRAME_RECONSTRUCTION_CORRECT 0x01
#define MSM_VIDC_FRAME_RECONSTRUCTION_APPROXIMATELY_CORRECT 0x02
#define MSM_VIDC_EXTRADATA_RECOVERY_POINT_SEI 0x00000009
struct msm_vidc_recoverysei_payload {
	unsigned int flags;
};

#define MSM_VIDC_EXTRADATA_ASPECT_RATIO 0x7F100003
struct msm_vidc_aspect_ratio_payload {
	unsigned int size;
	unsigned int version;
	unsigned int port_index;
	unsigned int aspect_width;
	unsigned int aspect_height;
};

#ifdef VENUS_USES_LEGACY_MISR_INFO
struct msm_vidc_misr_info {
	unsigned int misr_dpb_luma;
	unsigned int misr_dpb_chroma;
	unsigned int misr_opb_luma;
	unsigned int misr_opb_chroma;
};
#else
struct msm_vidc_misr_info {
	unsigned int misr_set;
	unsigned int misr_dpb_luma[8];
	unsigned int misr_dpb_chroma[8];
	unsigned int misr_opb_luma[8];
	unsigned int misr_opb_chroma[8];
};
#endif

#define MSM_VIDC_EXTRADATA_OUTPUT_CROP 0x0700000F
struct msm_vidc_output_crop_payload {
	unsigned int size;
	unsigned int version;
	unsigned int port_index;
	unsigned int left;
	unsigned int top;
	unsigned int display_width;
	unsigned int display_height;
	unsigned int width;
	unsigned int height;
	unsigned int frame_num;
	unsigned int bit_depth_y;
	unsigned int bit_depth_c;
	struct msm_vidc_misr_info misr_info[2];
};

struct msm_vidc_digital_zoom_payload {
	unsigned int size;
	unsigned int version;
	unsigned int port_index;
	unsigned int zoom_width;
	unsigned int zoom_height;
};

#define MSM_VIDC_EXTRADATA_INDEX 0x7F100002
struct msm_vidc_extradata_index {
	unsigned int type;
	union {
		struct msm_vidc_input_crop_payload input_crop;
		struct msm_vidc_digital_zoom_payload digital_zoom;
		struct msm_vidc_aspect_ratio_payload aspect_ratio;
	};
};

#define MSM_VIDC_EXTRADATA_PANSCAN_WINDOW 0x00000008
struct msm_vidc_panscan_window {
	unsigned int panscan_height_offset;
	unsigned int panscan_width_offset;
	unsigned int panscan_window_width;
	unsigned int panscan_window_height;
};
struct msm_vidc_panscan_window_payload {
	unsigned int num_panscan_windows;
	struct msm_vidc_panscan_window wnd[1];
};


#define MSM_VIDC_USERDATA_TYPE_FRAME 0x1
#define MSM_VIDC_USERDATA_TYPE_TOP_FIELD 0x2
#define MSM_VIDC_USERDATA_TYPE_BOTTOM_FIELD 0x3
#define MSM_VIDC_EXTRADATA_STREAM_USERDATA 0x0000000E
struct msm_vidc_stream_userdata_payload {
	unsigned int type;
	unsigned int data[1];
};

#define MSM_VIDC_EXTRADATA_FRAME_QP 0x0000000F
struct msm_vidc_frame_qp_payload {
	unsigned int frame_qp;
	unsigned int qp_sum;
	unsigned int skip_qp_sum;
	unsigned int skip_num_blocks;
	unsigned int total_num_blocks;
};

#define MSM_VIDC_EXTRADATA_FRAME_BITS_INFO 0x00000010
struct msm_vidc_frame_bits_info_payload {
	unsigned int frame_bits;
	unsigned int header_bits;
};

#define MSM_VIDC_EXTRADATA_S3D_FRAME_PACKING 0x00000006
struct msm_vidc_s3d_frame_packing_payload {
	unsigned int fpa_id;
	unsigned int cancel_flag;
	unsigned int fpa_type;
	unsigned int quin_cunx_flag;
	unsigned int content_interprtation_type;
	unsigned int spatial_flipping_flag;
	unsigned int frame0_flipped_flag;
	unsigned int field_views_flag;
	unsigned int current_frame_is_frame0_flag;
	unsigned int frame0_self_contained_flag;
	unsigned int frame1_self_contained_flag;
	unsigned int frame0_graid_pos_x;
	unsigned int frame0_graid_pos_y;
	unsigned int frame1_graid_pos_x;
	unsigned int frame1_graid_pos_y;
	unsigned int fpa_reserved_byte;
	unsigned int fpa_repetition_period;
	unsigned int fpa_extension_flag;
};

struct msm_vidc_vqzip_sei_payload {
	unsigned int size;
	unsigned int data[1];
};

struct msm_vidc_ubwc_cr_stats_info {
	unsigned int stats_tile_32;
	unsigned int stats_tile_64;
	unsigned int stats_tile_96;
	unsigned int stats_tile_128;
	unsigned int stats_tile_160;
	unsigned int stats_tile_192;
	unsigned int stats_tile_256;
};

struct msm_vidc_yuv_stats_payload {
	unsigned int frame_qp;
	unsigned int texture;
	unsigned int luma_in_q16;
	unsigned int frame_difference;
};

struct msm_vidc_roi_qp_payload {
	int upper_qp_offset;
	int lower_qp_offset;
	unsigned int b_roi_info;
	int mbi_info_size;
	unsigned int data[1];
};

struct msm_vidc_ipb_roi_qp_payload {
	signed int nUpperQpOffset[3];
	signed int nLowerQpOffset[3];
	unsigned int b_roi_info;
	int mbi_info_size;
	unsigned int data[1];
};

#define MSM_VIDC_EXTRADATA_ROI_QP 0x00000013
struct msm_vidc_roi_deltaqp_payload {
	unsigned int b_roi_info; /*Enable/Disable*/
	int mbi_info_size; /*Size of QP data*/
	unsigned int data[1];
};

#define MSM_VIDC_EXTRADATA_MASTERING_DISPLAY_COLOUR_SEI 0x00000015
struct msm_vidc_mastering_display_colour_sei_payload {
	unsigned int nDisplayPrimariesX[3];
	unsigned int nDisplayPrimariesY[3];
	unsigned int nWhitePointX;
	unsigned int nWhitePointY;
	unsigned int nMaxDisplayMasteringLuminance;
	unsigned int nMinDisplayMasteringLuminance;
};

#define MSM_VIDC_EXTRADATA_CONTENT_LIGHT_LEVEL_SEI 0x00000016
struct msm_vidc_content_light_level_sei_payload {
	unsigned int nMaxContentLight;
	unsigned int nMaxContentLight;
};

#define MSM_VIDC_EXTRADATA_HDR10PLUS_METADATA 0x0000001A
struct msm_vidc_hdr10plus_metadata_payload {
	unsigned int size;
	unsigned int data[1];
};

#define  MSM_VIDC_EXTRADATA_CVP_METADATA 0x0000001B
struct msm_vidc_enc_cvp_metadata_payload {
	unsigned int data[256];
};

/* video_format */
#define MSM_VIDC_COMPONENT 0
#define MSM_VIDC_PAL 1
#define MSM_VIDC_NTSC 2
#define MSM_VIDC_SECAM 3
#define MSM_VIDC_MAC 4
#define MSM_VIDC_UNSPECIFIED_FORMAT 5
#define MSM_VIDC_RESERVED_1_FORMAT 6
#define MSM_VIDC_RESERVED_2_FORMAT 7

/* See colour_primaries of ISO/IEC 14496 for significance */
/* color_primaries values */
#define MSM_VIDC_RESERVED_1 0
#define MSM_VIDC_BT709_5 1
#define MSM_VIDC_UNSPECIFIED 2
#define MSM_VIDC_RESERVED_2 3
#define MSM_VIDC_BT470_6_M 4
#define MSM_VIDC_BT601_6_625 5
#define MSM_VIDC_BT470_6_BG MSM_VIDC_BT601_6_625
#define MSM_VIDC_BT601_6_525 6
#define MSM_VIDC_SMPTE_240M 7
#define MSM_VIDC_GENERIC_FILM 8
#define MSM_VIDC_BT2020 9

/* matrix_coeffs values */
#define MSM_VIDC_MATRIX_RGB 0
#define MSM_VIDC_MATRIX_BT_709_5 1
#define MSM_VIDC_MATRIX_UNSPECIFIED 2
#define MSM_VIDC_MATRIX_RESERVED 3
#define MSM_VIDC_MATRIX_FCC_47 4
#define MSM_VIDC_MATRIX_601_6_625 5
#define MSM_VIDC_MATRIX_BT470_BG MSM_VIDC_MATRIX_601_6_625
#define MSM_VIDC_MATRIX_601_6_525 6
#define MSM_VIDC_MATRIX_SMPTE_170M MSM_VIDC_MATRIX_601_6_525
#define MSM_VIDC_MATRIX_SMPTE_240M 7
#define MSM_VIDC_MATRIX_Y_CG_CO 8
#define MSM_VIDC_MATRIX_BT_2020 9
#define MSM_VIDC_MATRIX_BT_2020_CONST 10

/* transfer_char values */
#define MSM_VIDC_TRANSFER_RESERVED_1 0
#define MSM_VIDC_TRANSFER_BT709_5 1
#define MSM_VIDC_TRANSFER_UNSPECIFIED 2
#define MSM_VIDC_TRANSFER_RESERVED_2 3
#define MSM_VIDC_TRANSFER_BT_470_6_M 4
#define MSM_VIDC_TRANSFER_BT_470_6_BG 5
#define MSM_VIDC_TRANSFER_601_6_625 6
#define MSM_VIDC_TRANSFER_601_6_525 MSM_VIDC_TRANSFER_601_6_625
#define MSM_VIDC_TRANSFER_SMPTE_240M 7
#define MSM_VIDC_TRANSFER_LINEAR 8
#define MSM_VIDC_TRANSFER_LOG_100_1 9
#define MSM_VIDC_TRANSFER_LOG_100_SQRT10_1 10
#define MSM_VIDC_TRANSFER_IEC_61966 11
#define MSM_VIDC_TRANSFER_BT_1361 12
#define MSM_VIDC_TRANSFER_SRGB 13
#define MSM_VIDC_TRANSFER_BT_2020_10 14
#define MSM_VIDC_TRANSFER_BT_2020_12 15
#define MSM_VIDC_TRANSFER_SMPTE_ST2084 16
#define MSM_VIDC_TRANSFER_SMPTE_ST428_1 17
#define MSM_VIDC_TRANSFER_HLG 18

#define MSM_VIDC_EXTRADATA_VUI_DISPLAY_INFO 0x7F100006
struct msm_vidc_vui_display_info_payload {
	unsigned int video_signal_present_flag;
	unsigned int video_format;
	unsigned int bit_depth_y;
	unsigned int bit_depth_c;
	unsigned int video_full_range_flag;
	unsigned int color_description_present_flag;
	unsigned int color_primaries;
	unsigned int transfer_characteristics;
	unsigned int matrix_coefficients;
	unsigned int chroma_location_info_present_flag;
	unsigned int chroma_format_idc;
	unsigned int separate_color_plane_flag;
	unsigned int chroma_sample_loc_type_top_field;
	unsigned int chroma_sample_loc_type_bottom_field;
};

#define  MSM_VIDC_EXTRADATA_HDR_HIST 0x7F100008
struct msm_vidc_extradata_hdr_hist_payload {
	unsigned int value_count[1024];
};

#define MSM_VIDC_EXTRADATA_MPEG2_SEQDISP 0x0000000D
struct msm_vidc_mpeg2_seqdisp_payload {
	unsigned int video_format;
	unsigned int color_descp;
	unsigned int color_primaries;
	unsigned int transfer_char;
	unsigned int matrix_coeffs;
	unsigned int disp_width;
	unsigned int disp_height;
};

struct msm_vidc_vc1_seqdisp_payload {
	unsigned int prog_seg_format;
	unsigned int uv_sampl_fmt;
	unsigned int color_format;
	unsigned int color_primaries;
	unsigned int transfer_char;
	unsigned int matrix_coeffs;
	unsigned int aspect_ratio;
	unsigned int aspect_horiz;
	unsigned int aspect_vert;
};

struct msm_vidc_input_crop_payload {
	unsigned int size;
	unsigned int version;
	unsigned int port_index;
	unsigned int left;
	unsigned int top;
	unsigned int width;
	unsigned int height;
};

/* VPx color_space values */
#define MSM_VIDC_CS_UNKNOWN 0
#define MSM_VIDC_CS_BT_601 1
#define MSM_VIDC_CS_BT_709 2
#define MSM_VIDC_CS_SMPTE_170 3
#define MSM_VIDC_CS_SMPTE_240 4
#define MSM_VIDC_CS_BT_2020 5
#define MSM_VIDC_CS_RESERVED 6
#define MSM_VIDC_CS_RGB 7
#define MSM_VIDC_EXTRADATA_VPX_COLORSPACE_INFO 0x00000014
struct msm_vidc_vpx_colorspace_payload {
	unsigned int color_space;
	unsigned int yuv_range_flag;
	unsigned int sumsampling_x;
	unsigned int sumsampling_y;
};

#define MSM_VIDC_EXTRADATA_METADATA_LTRINFO 0x7F100004
/* Don't use the #define below. It is to bypass checkpatch */
#define LTRINFO MSM_VIDC_EXTRADATA_METADATA_LTRINFO
struct msm_vidc_metadata_ltr_payload {
	unsigned int ltr_use_mark;
};

/* ptr[2]: event_notify: pixel_depth */
#define MSM_VIDC_BIT_DEPTH_8 0
#define MSM_VIDC_BIT_DEPTH_10 1
#define MSM_VIDC_BIT_DEPTH_UNSUPPORTED 0XFFFFFFFF

/*  ptr[3]: event_notify: pic_struct */
#define MSM_VIDC_PIC_STRUCT_MAYBE_INTERLACED 0x0
#define MSM_VIDC_PIC_STRUCT_PROGRESSIVE 0x1

/*default when layer ID isn't specified*/
#define MSM_VIDC_ALL_LAYER_ID 0xFF

/* V4L2_CID_MPEG_VIDC_VENC_HDR_INFO payload index */
enum msm_vidc_hdr_info_types {
	MSM_VIDC_RGB_PRIMARY_00,
	MSM_VIDC_RGB_PRIMARY_01,
	MSM_VIDC_RGB_PRIMARY_10,
	MSM_VIDC_RGB_PRIMARY_11,
	MSM_VIDC_RGB_PRIMARY_20,
	MSM_VIDC_RGB_PRIMARY_21,
	MSM_VIDC_WHITEPOINT_X,
	MSM_VIDC_WHITEPOINT_Y,
	MSM_VIDC_MAX_DISP_LUM,
	MSM_VIDC_MIN_DISP_LUM,
	MSM_VIDC_RGB_MAX_CLL,
	MSM_VIDC_RGB_MAX_FLL,
};

enum msm_vidc_plane_reserved_field_types {
	MSM_VIDC_BUFFER_FD,
	MSM_VIDC_DATA_OFFSET,
	MSM_VIDC_COMP_RATIO,
	MSM_VIDC_INPUT_TAG_1,
	MSM_VIDC_INPUT_TAG_2,
};

enum msm_vidc_cb_event_types {
	MSM_VIDC_HEIGHT,
	MSM_VIDC_WIDTH,
	MSM_VIDC_BIT_DEPTH,
	MSM_VIDC_PIC_STRUCT,
	MSM_VIDC_COLOR_SPACE,
	MSM_VIDC_FW_MIN_COUNT,
};
#endif
