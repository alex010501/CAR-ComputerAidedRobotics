static const uint8_t fs_debugfont_glsl[339] =
{
	0x46, 0x53, 0x48, 0x0b, 0xb8, 0xbe, 0x22, 0x66, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH..."f.......s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor.......
	0x00, 0x00, 0x00, 0x2b, 0x01, 0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, // ...+...varying v
	0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x76, 0x61, // ec4 v_color0;.va
	0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, // rying vec4 v_col
	0x6f, 0x72, 0x31, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, // or1;.varying vec
	0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, // 2 v_texcoord0;.u
	0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x32, 0x44, // niform sampler2D
	0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x3b, 0x0a, 0x76, 0x6f, 0x69, //  s_texColor;.voi
	0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x76, 0x65, // d main ().{.  ve
	0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, // c4 tmpvar_1;.  t
	0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x6d, 0x69, 0x78, 0x20, 0x28, 0x76, // mpvar_1 = mix (v
	0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x31, 0x2c, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, // _color1, v_color
	0x30, 0x2c, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x20, 0x28, 0x73, 0x5f, // 0, texture2D (s_
	0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, // texColor, v_texc
	0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29, 0x2e, 0x78, 0x78, 0x78, 0x78, 0x29, 0x3b, 0x0a, 0x20, 0x20, // oord0).xxxx);.  
	0x69, 0x66, 0x20, 0x28, 0x28, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x77, 0x20, // if ((tmpvar_1.w 
	0x3c, 0x20, 0x30, 0x2e, 0x30, 0x30, 0x33, 0x39, 0x32, 0x31, 0x35, 0x36, 0x39, 0x29, 0x29, 0x20, // < 0.003921569)) 
	0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 0x73, 0x63, 0x61, 0x72, 0x64, 0x3b, 0x0a, 0x20, // {.    discard;. 
	0x20, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, //  };.  gl_FragCol
	0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x7d, // or = tmpvar_1;.}
	0x0a, 0x0a, 0x00,                                                                               // ...
};
static const uint8_t fs_debugfont_essl[362] =
{
	0x46, 0x53, 0x48, 0x0b, 0xb8, 0xbe, 0x22, 0x66, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH..."f.......s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor.......
	0x00, 0x00, 0x00, 0x42, 0x01, 0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, // ...B...varying h
	0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, // ighp vec4 v_colo
	0x72, 0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, 0x68, // r0;.varying high
	0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x31, 0x3b, // p vec4 v_color1;
	0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76, // .varying highp v
	0x65, 0x63, 0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, // ec2 v_texcoord0;
	0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, // .uniform sampler
	0x32, 0x44, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x3b, 0x0a, 0x76, // 2D s_texColor;.v
	0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, // oid main ().{.  
	0x6c, 0x6f, 0x77, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, // lowp vec4 tmpvar
	0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, 0x3d, // _1;.  tmpvar_1 =
	0x20, 0x6d, 0x69, 0x78, 0x20, 0x28, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x31, 0x2c, 0x20, //  mix (v_color1, 
	0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2c, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, // v_color0, textur
	0x65, 0x32, 0x44, 0x20, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, // e2D (s_texColor,
	0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29, 0x2e, 0x78, 0x78, //  v_texcoord0).xx
	0x78, 0x78, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x28, 0x74, 0x6d, 0x70, 0x76, // xx);.  if ((tmpv
	0x61, 0x72, 0x5f, 0x31, 0x2e, 0x77, 0x20, 0x3c, 0x20, 0x30, 0x2e, 0x30, 0x30, 0x33, 0x39, 0x32, // ar_1.w < 0.00392
	0x31, 0x35, 0x36, 0x39, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 0x73, // 1569)) {.    dis
	0x63, 0x61, 0x72, 0x64, 0x3b, 0x0a, 0x20, 0x20, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, // card;.  };.  gl_
	0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, // FragColor = tmpv
	0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                     // ar_1;.}...
};
static const uint8_t fs_debugfont_spv[1095] =
{
	0x46, 0x53, 0x48, 0x0b, 0xb8, 0xbe, 0x22, 0x66, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH..."f.......s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, // _texColor0......
	0x02, 0x22, 0x00, 0x1c, 0x04, 0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x0b, // .".......#......
	0x00, 0x08, 0x00, 0xc8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00, 0x01, // ................
	0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c, 0x53, 0x4c, 0x2e, // ...........GLSL.
	0x73, 0x74, 0x64, 0x2e, 0x34, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, // std.450.........
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x09, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, // ................
	0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x70, // ...main....m...p
	0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00, 0x10, 0x00, 0x03, 0x00, 0x04, // ...t............
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0xf4, // ................
	0x01, 0x00, 0x00, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, // ...........main.
	0x00, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, // .......*...s_tex
	0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x00, 0x00, 0x00, 0x05, // ColorSampler....
	0x00, 0x07, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, // ...-...s_texColo
	0x72, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x6d, // rTexture.......m
	0x00, 0x00, 0x00, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00, 0x05, // ...v_color0.....
	0x00, 0x05, 0x00, 0x70, 0x00, 0x00, 0x00, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x31, 0x00, // ...p...v_color1.
	0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x74, 0x00, 0x00, 0x00, 0x76, 0x5f, 0x74, 0x65, 0x78, // .......t...v_tex
	0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x00, 0x05, 0x00, 0x06, 0x00, 0x83, 0x00, 0x00, 0x00, 0x62, // coord0.........b
	0x67, 0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x00, 0x00, 0x47, // gfx_FragData0..G
	0x00, 0x04, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, // ...*...".......G
	0x00, 0x04, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x47, // ...*...!.......G
	0x00, 0x04, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, // ...-...".......G
	0x00, 0x04, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x47, // ...-...!.......G
	0x00, 0x04, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, // ...m...........G
	0x00, 0x04, 0x00, 0x70, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, // ...p...........G
	0x00, 0x04, 0x00, 0x74, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x47, // ...t...........G
	0x00, 0x04, 0x00, 0x83, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, // ................
	0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, // .......!........
	0x00, 0x00, 0x00, 0x1a, 0x00, 0x02, 0x00, 0x06, 0x00, 0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x07, // ................
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x19, 0x00, 0x09, 0x00, 0x08, 0x00, 0x00, 0x00, 0x07, // ... ............
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x0b, // ................
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x0d, // ................
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x29, // ........... ...)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x29, // ...........;...)
	0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x2c, // ...*....... ...,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x2c, // ...........;...,
	0x00, 0x00, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x03, 0x00, 0x39, // ...-...........9
	0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00, 0x61, // .......+.......a
	0x00, 0x00, 0x00, 0x81, 0x80, 0x80, 0x3b, 0x14, 0x00, 0x02, 0x00, 0x62, 0x00, 0x00, 0x00, 0x20, // ......;....b... 
	0x00, 0x04, 0x00, 0x69, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, // ...i...........;
	0x00, 0x04, 0x00, 0x69, 0x00, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3b, // ...i...m.......;
	0x00, 0x04, 0x00, 0x69, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, // ...i...p....... 
	0x00, 0x04, 0x00, 0x73, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x3b, // ...s...........;
	0x00, 0x04, 0x00, 0x73, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, // ...s...t....... 
	0x00, 0x04, 0x00, 0x82, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, // ...............;
	0x00, 0x04, 0x00, 0x82, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x36, // ...............6
	0x00, 0x05, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, // ................
	0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x05, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x06, // ...........=....
	0x00, 0x00, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x08, // ...+...*...=....
	0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, // .......-...=....
	0x00, 0x00, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, // ...n...m...=....
	0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x0b, // ...q...p...=....
	0x00, 0x00, 0x00, 0x75, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x56, 0x00, 0x05, 0x00, 0x39, // ...u...t...V...9
	0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x57, // ...........+...W
	0x00, 0x05, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xc1, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00, 0x75, // ...............u
	0x00, 0x00, 0x00, 0x4f, 0x00, 0x09, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xa9, 0x00, 0x00, 0x00, 0xc1, // ...O............
	0x00, 0x00, 0x00, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xc7, // ................
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x6e, // ...........q...n
	0x00, 0x00, 0x00, 0xa9, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xac, // .......Q........
	0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xb8, 0x00, 0x05, 0x00, 0x62, // ...............b
	0x00, 0x00, 0x00, 0xad, 0x00, 0x00, 0x00, 0xac, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 0xf7, // ...........a....
	0x00, 0x03, 0x00, 0xaf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x04, 0x00, 0xad, // ................
	0x00, 0x00, 0x00, 0xae, 0x00, 0x00, 0x00, 0xaf, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0xae, // ................
	0x00, 0x00, 0x00, 0xfc, 0x00, 0x01, 0x00, 0xf8, 0x00, 0x02, 0x00, 0xaf, 0x00, 0x00, 0x00, 0x3e, // ...............>
	0x00, 0x03, 0x00, 0x83, 0x00, 0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, // ...............8
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,                                                       // .......
};
static const uint8_t fs_debugfont_dx11[547] =
{
	0x46, 0x53, 0x48, 0x0b, 0xb8, 0xbe, 0x22, 0x66, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0a, 0x73, // FSH..."f.......s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, // _texColor0......
	0x00, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x44, 0x58, 0x42, 0x43, 0x5a, 0xd5, 0xe8, 0x3a, 0x43, // .......DXBCZ..:C
	0x7d, 0xa8, 0x34, 0xa8, 0x0a, 0x2d, 0x0c, 0xa2, 0xce, 0x50, 0x4f, 0x01, 0x00, 0x00, 0x00, 0xf8, // }.4..-...PO.....
	0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0xb8, 0x00, 0x00, 0x00, 0xec, // .......,........
	0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x84, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, // ...ISGN.........
	0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, // ...h............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x00, // ...........t....
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, // ................
	0x0f, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, // ...t............
	0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x7a, 0x00, 0x00, 0x00, 0x00, // ...........z....
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, // ................
	0x03, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x43, // ...SV_POSITION.C
	0x4f, 0x4c, 0x4f, 0x52, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0x4f, // OLOR.TEXCOORD..O
	0x53, 0x47, 0x4e, 0x2c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, // SGN,........... 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x54, 0x41, 0x52, 0x47, 0x45, 0x54, // .......SV_TARGET
	0x00, 0xab, 0xab, 0x53, 0x48, 0x44, 0x52, 0x04, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, // ...SHDR....@...A
	0x00, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x03, 0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, // ...Z....`......X
	0x18, 0x00, 0x04, 0x00, 0x70, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x62, // ....p......UU..b
	0x10, 0x00, 0x03, 0xf2, 0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0xf2, // ...........b....
	0x10, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0x32, 0x10, 0x10, 0x00, 0x03, // .......b...2....
	0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, // ...e.... ......h
	0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x09, 0xf2, 0x00, 0x10, 0x00, 0x00, // .......E........
	0x00, 0x00, 0x00, 0x46, 0x10, 0x10, 0x00, 0x03, 0x00, 0x00, 0x00, 0x46, 0x7e, 0x10, 0x00, 0x00, // ...F.......F~...
	0x00, 0x00, 0x00, 0x00, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xf2, // ....`...........
	0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x1e, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, // .......F.......F
	0x1e, 0x10, 0x80, 0x41, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x09, 0xf2, // ...A.......2....
	0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, // ...............F
	0x0e, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x1e, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x31, // .......F.......1
	0x00, 0x00, 0x07, 0x12, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3a, 0x00, 0x10, 0x00, 0x00, // ...........:....
	0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x81, 0x80, 0x80, 0x3b, 0x0d, 0x00, 0x04, 0x03, 0x0a, // ....@.....;.....
	0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0xf2, 0x20, 0x10, 0x00, 0x00, // .......6.... ...
	0x00, 0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, // ...F.......>....
	0x00, 0x00, 0x00,                                                                               // ...
};
static const uint8_t fs_debugfont_mtl[843] =
{
	0x46, 0x53, 0x48, 0x0b, 0xb8, 0xbe, 0x22, 0x66, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x11, 0x73, // FSH..."f.......s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, // _texColorSampler
	0x11, 0x01, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x73, 0x5f, 0x74, 0x65, 0x78, // ...........s_tex
	0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x11, 0x01, 0xff, 0xff, // ColorTexture....
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, // .......s_texColo
	0x72, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe8, 0x02, 0x00, 0x00, 0x23, // r..............#
	0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x5f, 0x73, // include <metal_s
	0x74, 0x64, 0x6c, 0x69, 0x62, 0x3e, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, // tdlib>.#include 
	0x3c, 0x73, 0x69, 0x6d, 0x64, 0x2f, 0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e, 0x0a, 0x0a, 0x75, // <simd/simd.h>..u
	0x73, 0x69, 0x6e, 0x67, 0x20, 0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63, 0x65, 0x20, 0x6d, // sing namespace m
	0x65, 0x74, 0x61, 0x6c, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, // etal;..struct xl
	0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x0a, 0x7b, 0x0a, // atMtlMain_out.{.
	0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x62, 0x67, 0x66, 0x78, 0x5f, //     float4 bgfx_
	0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x20, 0x5b, 0x5b, 0x63, 0x6f, 0x6c, 0x6f, // FragData0 [[colo
	0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, // r(0)]];.};..stru
	0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, // ct xlatMtlMain_i
	0x6e, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x76, // n.{.    float4 v
	0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, // _color0 [[user(l
	0x6f, 0x63, 0x6e, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, // ocn0)]];.    flo
	0x61, 0x74, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x31, 0x20, 0x5b, 0x5b, 0x75, // at4 v_color1 [[u
	0x73, 0x65, 0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x31, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x20, 0x20, // ser(locn1)]];.  
	0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, //   float2 v_texco
	0x6f, 0x72, 0x64, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, // ord0 [[user(locn
	0x32, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x66, 0x72, 0x61, 0x67, 0x6d, 0x65, // 2)]];.};..fragme
	0x6e, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, // nt xlatMtlMain_o
	0x75, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x28, 0x78, // ut xlatMtlMain(x
	0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e, 0x20, 0x69, 0x6e, // latMtlMain_in in
	0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, 0x69, 0x6e, 0x5d, 0x5d, 0x2c, 0x20, 0x74, //  [[stage_in]], t
	0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x64, 0x3c, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x3e, 0x20, // exture2d<float> 
	0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x5b, 0x5b, 0x74, 0x65, 0x78, // s_texColor [[tex
	0x74, 0x75, 0x72, 0x65, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x2c, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, // ture(0)]], sampl
	0x65, 0x72, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, // er s_texColorSam
	0x70, 0x6c, 0x65, 0x72, 0x20, 0x5b, 0x5b, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x28, 0x30, // pler [[sampler(0
	0x29, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, // )]]).{.    xlatM
	0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x6f, 0x75, 0x74, 0x20, 0x3d, // tlMain_out out =
	0x20, 0x7b, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, //  {};.    float4 
	0x5f, 0x31, 0x39, 0x30, 0x20, 0x3d, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, // _190 = s_texColo
	0x72, 0x2e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, // r.sample(s_texCo
	0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x2c, 0x20, 0x69, 0x6e, 0x2e, 0x76, // lorSampler, in.v
	0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, // _texcoord0);.   
	0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x5f, 0x31, 0x39, 0x36, 0x20, 0x3d, 0x20, 0x6d, //  float4 _196 = m
	0x69, 0x78, 0x28, 0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x31, 0x2c, 0x20, // ix(in.v_color1, 
	0x69, 0x6e, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x2c, 0x20, 0x5f, 0x31, 0x39, // in.v_color0, _19
	0x30, 0x2e, 0x78, 0x78, 0x78, 0x78, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x20, // 0.xxxx);.    if 
	0x28, 0x5f, 0x31, 0x39, 0x36, 0x2e, 0x77, 0x20, 0x3c, 0x20, 0x30, 0x2e, 0x30, 0x30, 0x33, 0x39, // (_196.w < 0.0039
	0x32, 0x31, 0x35, 0x36, 0x38, 0x38, 0x35, 0x39, 0x33, 0x36, 0x38, 0x35, 0x36, 0x32, 0x36, 0x39, // 2156885936856269
	0x38, 0x33, 0x36, 0x34, 0x32, 0x35, 0x37, 0x38, 0x31, 0x32, 0x35, 0x29, 0x0a, 0x20, 0x20, 0x20, // 83642578125).   
	0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 0x73, 0x63, 0x61, //  {.        disca
	0x72, 0x64, 0x5f, 0x66, 0x72, 0x61, 0x67, 0x6d, 0x65, 0x6e, 0x74, 0x28, 0x29, 0x3b, 0x0a, 0x20, // rd_fragment();. 
	0x20, 0x20, 0x20, 0x7d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x62, 0x67, 0x66, //    }.    out.bgf
	0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x20, 0x3d, 0x20, 0x5f, 0x31, // x_FragData0 = _1
	0x39, 0x36, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, // 96;.    return o
	0x75, 0x74, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00, 0x00, 0x20, 0x00,                               // ut;.}.... .
};
extern const uint8_t* fs_debugfont_pssl;
extern const uint32_t fs_debugfont_pssl_size;
