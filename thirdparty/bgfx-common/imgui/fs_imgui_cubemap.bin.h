static const uint8_t fs_imgui_cubemap_glsl[281] =
{
	0x46, 0x53, 0x48, 0x03, 0xe3, 0xc2, 0x5c, 0x65, 0x02, 0x00, 0x0a, 0x75, 0x5f, 0x69, 0x6d, 0x61, // FSH....e...u_ima
	0x67, 0x65, 0x4c, 0x6f, 0x64, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, // geLod.......s_te
	0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0xe8, 0x00, 0x00, 0x00, // xColor..........
	0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65, // varying highp ve
	0x63, 0x33, 0x20, 0x76, 0x5f, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x3b, 0x0a, 0x75, 0x6e, 0x69, // c3 v_normal;.uni
	0x66, 0x6f, 0x72, 0x6d, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, // form highp float
	0x20, 0x75, 0x5f, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x4c, 0x6f, 0x64, 0x3b, 0x0a, 0x75, 0x6e, 0x69, //  u_imageLod;.uni
	0x66, 0x6f, 0x72, 0x6d, 0x20, 0x6c, 0x6f, 0x77, 0x70, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, // form lowp sample
	0x72, 0x43, 0x75, 0x62, 0x65, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, // rCube s_texColor
	0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, // ;.void main ().{
	0x0a, 0x20, 0x20, 0x6c, 0x6f, 0x77, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, // .  lowp vec4 tmp
	0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // var_1;.  tmpvar_
	0x31, 0x20, 0x3d, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x43, 0x75, 0x62, 0x65, 0x4c, // 1 = textureCubeL
	0x6f, 0x64, 0x20, 0x20, 0x20, 0x20, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, // od    (s_texColo
	0x72, 0x2c, 0x20, 0x76, 0x5f, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x2c, 0x20, 0x75, 0x5f, 0x69, // r, v_normal, u_i
	0x6d, 0x61, 0x67, 0x65, 0x4c, 0x6f, 0x64, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, // mageLod);.  gl_F
	0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, // ragColor = tmpva
	0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                           // r_1;.}...
};
static const uint8_t fs_imgui_cubemap_dx9[290] =
{
	0x46, 0x53, 0x48, 0x03, 0xe3, 0xc2, 0x5c, 0x65, 0x01, 0x00, 0x0a, 0x75, 0x5f, 0x69, 0x6d, 0x61, // FSH....e...u_ima
	0x67, 0x65, 0x4c, 0x6f, 0x64, 0x14, 0x01, 0x00, 0x00, 0x01, 0x00, 0x04, 0x01, 0x00, 0x03, 0xff, // geLod...........
	0xff, 0xfe, 0xff, 0x2e, 0x00, 0x43, 0x54, 0x41, 0x42, 0x1c, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, // .....CTAB.......
	0x00, 0x00, 0x03, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x81, 0x00, // ................
	0x00, 0x7c, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, // .|...D..........
	0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // .P.......`......
	0x00, 0x01, 0x00, 0x00, 0x00, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, // .....l.......s_t
	0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0xab, 0x04, 0x00, 0x0e, 0x00, 0x01, 0x00, 0x01, // exColor.........
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x69, 0x6d, 0x61, 0x67, 0x65, // .........u_image
	0x4c, 0x6f, 0x64, 0x00, 0xab, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, // Lod.............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x73, 0x5f, 0x33, 0x5f, 0x30, 0x00, 0x4d, 0x69, 0x63, 0x72, // .....ps_3_0.Micr
	0x6f, 0x73, 0x6f, 0x66, 0x74, 0x20, 0x28, 0x52, 0x29, 0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53, // osoft (R) HLSL S
	0x68, 0x61, 0x64, 0x65, 0x72, 0x20, 0x43, 0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x39, // hader Compiler 9
	0x2e, 0x32, 0x39, 0x2e, 0x39, 0x35, 0x32, 0x2e, 0x33, 0x31, 0x31, 0x31, 0x00, 0x1f, 0x00, 0x00, // .29.952.3111....
	0x02, 0x03, 0x00, 0x00, 0x80, 0x00, 0x00, 0x07, 0x90, 0x1f, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, // ................
	0x98, 0x00, 0x08, 0x0f, 0xa0, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0xe4, // ................
	0x90, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x08, 0x80, 0x00, 0x00, 0x00, 0xa0, 0x5f, 0x00, 0x00, // ............._..
	0x03, 0x00, 0x08, 0x0f, 0x80, 0x00, 0x00, 0xe4, 0x80, 0x00, 0x08, 0xe4, 0xa0, 0xff, 0xff, 0x00, // ................
	0x00, 0x00,                                                                                     // ..
};
static const uint8_t fs_imgui_cubemap_dx11[1269] =
{
	0x46, 0x53, 0x48, 0x03, 0xe3, 0xc2, 0x5c, 0x65, 0x01, 0x00, 0x0a, 0x75, 0x5f, 0x69, 0x6d, 0x61, // FSH....e...u_ima
	0x67, 0x65, 0x4c, 0x6f, 0x64, 0x14, 0x00, 0x24, 0x0a, 0x01, 0x00, 0xd4, 0x04, 0x44, 0x58, 0x42, // geLod..$.....DXB
	0x43, 0x27, 0x33, 0xa4, 0x06, 0x75, 0x65, 0xf9, 0x2c, 0x5c, 0xba, 0x63, 0x69, 0x27, 0x59, 0xb8, // C'3..ue.,..ci'Y.
	0xfb, 0x01, 0x00, 0x00, 0x00, 0xd4, 0x04, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, // .............4..
	0x00, 0x48, 0x03, 0x00, 0x00, 0x9c, 0x03, 0x00, 0x00, 0xd0, 0x03, 0x00, 0x00, 0x58, 0x04, 0x00, // .H...........X..
	0x00, 0x52, 0x44, 0x45, 0x46, 0x0c, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xbc, 0x00, 0x00, // .RDEF...........
	0x00, 0x03, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x04, 0xff, 0xff, 0x00, 0x91, 0x00, // ................
	0x00, 0xdb, 0x02, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // .....|..........
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x01, 0x00, 0x00, 0x00, 0x97, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, // ................
	0x00, 0x09, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x0d, 0x00, 0x00, 0x00, 0xb2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x73, // .....s_texColors
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x00, // _texColorampler.
	0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, // s_texColors_texC
	0x6f, 0x6c, 0x6f, 0x72, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x24, 0x47, 0x6c, 0x6f, 0x62, // olorexture.$Glob
	0x61, 0x6c, 0x73, 0x00, 0xab, 0xb2, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, // als.............
	0x00, 0x30, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x02, 0x00, // .0..............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x02, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, // .....(..........
	0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x02, 0x00, // .............4..
	0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x00, // . ...@.......<..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x02, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, // .....L...`...@..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x02, 0x00, // .....<.......V..
	0x00, 0xa0, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x00, // .....@.......<..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x02, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, // .....].......@..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x02, 0x00, // .....<.......g..
	0x00, 0x20, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x00, // . ...@.......<..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x02, 0x00, 0x00, 0x60, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, // .....r...`...@..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x02, 0x00, // .....<..........
	0x00, 0xa0, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x02, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x02, 0x00, 0x00, 0xa0, 0x09, 0x00, 0x00, 0x40, 0x00, 0x00, // .............@..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4, 0x02, 0x00, // .....<..........
	0x00, 0xe0, 0x09, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x00, // .....@.......<..
	0x00, 0x00, 0x00, 0x00, 0x00, 0xb4, 0x02, 0x00, 0x00, 0x20, 0x0a, 0x00, 0x00, 0x04, 0x00, 0x00, // ......... ......
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x02, 0x00, // ................
	0x00, 0x24, 0x0a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xc0, 0x02, 0x00, // .$..............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, 0x74, 0x00, // .....u_viewRect.
	0xab, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x54, 0x65, 0x78, 0x65, 0x6c, 0x00, 0x75, 0x5f, 0x76, // .u_viewTexel.u_v
	0x69, 0x65, 0x77, 0x00, 0xab, 0x03, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, // iew.............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x69, 0x6e, 0x76, 0x56, 0x69, 0x65, 0x77, 0x00, 0x75, // .....u_invView.u
	0x5f, 0x70, 0x72, 0x6f, 0x6a, 0x00, 0x75, 0x5f, 0x69, 0x6e, 0x76, 0x50, 0x72, 0x6f, 0x6a, 0x00, // _proj.u_invProj.
	0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x75, 0x5f, 0x69, 0x6e, 0x76, // u_viewProj.u_inv
	0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, // ViewProj.u_model
	0x00, 0x03, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ......... ......
	0x00, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x00, 0x75, 0x5f, 0x6d, // .u_modelView.u_m
	0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x75, 0x5f, 0x61, // odelViewProj.u_a
	0x6c, 0x70, 0x68, 0x61, 0x52, 0x65, 0x66, 0x00, 0xab, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01, // lphaRef.........
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x69, 0x6d, 0x61, 0x67, 0x65, // .........u_image
	0x4c, 0x6f, 0x64, 0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x20, 0x28, 0x52, // Lod.Microsoft (R
	0x29, 0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x20, 0x43, 0x6f, // ) HLSL Shader Co
	0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x39, 0x2e, 0x32, 0x39, 0x2e, 0x39, 0x35, 0x32, 0x2e, // mpiler 9.29.952.
	0x33, 0x31, 0x31, 0x31, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x4c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // 3111.ISGNL......
	0x00, 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // .....8..........
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, // .............D..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x07, 0x07, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, // .....SV_POSITION
	0x00, 0x4e, 0x4f, 0x52, 0x4d, 0x41, 0x4c, 0x00, 0xab, 0x4f, 0x53, 0x47, 0x4e, 0x2c, 0x00, 0x00, // .NORMAL..OSGN,..
	0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ......... ......
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, // ................
	0x00, 0x53, 0x56, 0x5f, 0x54, 0x41, 0x52, 0x47, 0x45, 0x54, 0x00, 0xab, 0xab, 0x53, 0x48, 0x44, // .SV_TARGET...SHD
	0x52, 0x80, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, // R....@... ...Y..
	0x04, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa3, 0x00, 0x00, 0x00, 0x5a, 0x00, 0x00, // .F. .........Z..
	0x03, 0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x30, 0x00, 0x04, 0x00, 0x70, 0x10, // ..`......X0...p.
	0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0x72, 0x10, 0x10, // .....UU..b...r..
	0x00, 0x01, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, // .....e.... .....
	0x00, 0x48, 0x00, 0x00, 0x0c, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x12, 0x10, // .H.... ......F..
	0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x7e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x10, // .....F~.......`.
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x80, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa2, 0x00, 0x00, // ....... ........
	0x00, 0x3e, 0x00, 0x00, 0x01, 0x53, 0x54, 0x41, 0x54, 0x74, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // .>...STATt......
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x30, 0x0a,                                                                   // ...0.
};
