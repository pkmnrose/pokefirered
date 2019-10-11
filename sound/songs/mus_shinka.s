	.include "MPlayDef.s"
	.section .rodata
	.global mus_shinka
	.align 2
	.equ mus_shinka_grp, voicegroup026
	.equ mus_shinka_pri, 1
	.equ mus_shinka_rev, reverb_set+50

mus_shinka_1: @ 86BD640
	.byte KEYSH, 0x00
	.byte TEMPO, 0x3C
	.byte VOICE, 0x3C
	.byte VOL, 0x50
	.byte N06
	.byte Gn3
	.byte v080
	.byte W24
	.byte Gn3
	.byte v056
	.byte W24
	.byte Gn3
	.byte v060
	.byte W24
	.byte Gn3
	.byte v064
	.byte W24
mus_shinka_1_86BD655: @ 86BD655
	.byte N06
	.byte Gn3
	.byte v068
	.byte W24
	.byte Gn3
	.byte v072
	.byte W24
	.byte Gn3
	.byte v076
	.byte W24
	.byte N24
	.byte An3
	.byte v080
	.byte W09
	.byte MOD, 0x06
	.byte W15
	.byte PEND
mus_shinka_1_86BD667: @ 86BD667
	.byte MOD, 0x00
	.byte N06
	.byte Gn3
	.byte v080
	.byte W24
	.byte Gn3
	.byte v056
	.byte W24
	.byte Gn3
	.byte v060
	.byte W24
	.byte Gn3
	.byte v064
	.byte W24
	.byte PEND
mus_shinka_1_86BD677: @ 86BD677
	.byte N06
	.byte Gn3
	.byte v068
	.byte W24
	.byte Gn3
	.byte v072
	.byte W24
	.byte Gn3
	.byte v076
	.byte W24
	.byte N24
	.byte Bn3
	.byte v080
	.byte W09
	.byte MOD, 0x06
	.byte W15
	.byte PEND
	.byte PATT
	.word mus_shinka_1_86BD667
	.byte PATT
	.word mus_shinka_1_86BD655
	.byte PATT
	.word mus_shinka_1_86BD667
	.byte PATT
	.word mus_shinka_1_86BD677
mus_shinka_1_86BD69D: @ 86BD69D
	.byte MOD, 0x00
	.byte N06
	.byte An3
	.byte v080
	.byte W24
	.byte An3
	.byte v056
	.byte W24
	.byte An3
	.byte v060
	.byte W24
	.byte An3
	.byte v064
	.byte W24
	.byte PEND
mus_shinka_1_86BD6AD: @ 86BD6AD
	.byte N06
	.byte An3
	.byte v068
	.byte W24
	.byte An3
	.byte v072
	.byte W24
	.byte An3
	.byte v076
	.byte W24
	.byte N24
	.byte Bn3
	.byte v080
	.byte W09
	.byte MOD, 0x06
	.byte W15
	.byte PEND
	.byte PATT
	.word mus_shinka_1_86BD69D
mus_shinka_1_86BD6C4: @ 86BD6C4
	.byte N06
	.byte An3
	.byte v068
	.byte W24
	.byte An3
	.byte v072
	.byte W24
	.byte An3
	.byte v076
	.byte W24
	.byte N24
	.byte Cs4
	.byte v080
	.byte W09
	.byte MOD, 0x06
	.byte W15
	.byte PEND
	.byte PATT
	.word mus_shinka_1_86BD69D
	.byte PATT
	.word mus_shinka_1_86BD6AD
	.byte PATT
	.word mus_shinka_1_86BD69D
	.byte PATT
	.word mus_shinka_1_86BD6C4
	.byte GOTO
	.word mus_shinka_1_86BD69D
	.byte MOD, 0x00
	.byte FINE

mus_shinka_2: @ 86BD6F2
	.byte KEYSH, 0x00
	.byte VOICE, 0x3C
	.byte PAN, 0x50
	.byte VOL, 0x50
	.byte N06
	.byte Cn3
	.byte v080
	.byte W24
	.byte Dn3
	.byte v056
	.byte W24
	.byte Cn3
	.byte v060
	.byte W24
	.byte Dn3
	.byte v064
	.byte W24
mus_shinka_2_86BD707: @ 86BD707
	.byte N06
	.byte Cn3
	.byte v068
	.byte W24
	.byte Dn3
	.byte v072
	.byte W24
	.byte Cn3
	.byte v076
	.byte W24
	.byte N24
	.byte Dn3
	.byte v080
	.byte W09
	.byte MOD, 0x06
	.byte W15
	.byte PEND
mus_shinka_2_86BD719: @ 86BD719
	.byte MOD, 0x00
	.byte N06
	.byte Cn3
	.byte v080
	.byte W24
	.byte Dn3
	.byte v056
	.byte W24
	.byte Cn3
	.byte v060
	.byte W24
	.byte Dn3
	.byte v064
	.byte W24
	.byte PEND
mus_shinka_2_86BD729: @ 86BD729
	.byte N06
	.byte Cn3
	.byte v068
	.byte W24
	.byte Dn3
	.byte v072
	.byte W24
	.byte Cn3
	.byte v076
	.byte W24
	.byte N24
	.byte Fs3
	.byte v080
	.byte W09
	.byte MOD, 0x06
	.byte W15
	.byte PEND
	.byte PATT
	.word mus_shinka_2_86BD719
	.byte PATT
	.word mus_shinka_2_86BD707
	.byte PATT
	.word mus_shinka_2_86BD719
	.byte PATT
	.word mus_shinka_2_86BD729
mus_shinka_2_86BD74F: @ 86BD74F
	.byte MOD, 0x00
	.byte N06
	.byte Dn3
	.byte v080
	.byte W24
	.byte En3
	.byte v056
	.byte W24
	.byte Dn3
	.byte v060
	.byte W24
	.byte En3
	.byte v064
	.byte W24
	.byte PEND
mus_shinka_2_86BD75F: @ 86BD75F
	.byte N06
	.byte Dn3
	.byte v068
	.byte W24
	.byte En3
	.byte v072
	.byte W24
	.byte Dn3
	.byte v076
	.byte W24
	.byte N24
	.byte En3
	.byte v080
	.byte W09
	.byte MOD, 0x06
	.byte W15
	.byte PEND
	.byte PATT
	.word mus_shinka_2_86BD74F
mus_shinka_2_86BD776: @ 86BD776
	.byte N06
	.byte Dn3
	.byte v068
	.byte W24
	.byte En3
	.byte v072
	.byte W24
	.byte Dn3
	.byte v076
	.byte W24
	.byte N24
	.byte Gs3
	.byte v080
	.byte W09
	.byte MOD, 0x06
	.byte W15
	.byte PEND
	.byte PATT
	.word mus_shinka_2_86BD74F
	.byte PATT
	.word mus_shinka_2_86BD75F
	.byte PATT
	.word mus_shinka_2_86BD74F
	.byte PATT
	.word mus_shinka_2_86BD776
	.byte GOTO
	.word mus_shinka_2_86BD74F
	.byte MOD, 0x00
	.byte FINE

mus_shinka_3: @ 86BD7A4
	.byte KEYSH, 0x00
	.byte VOICE, 0x51
	.byte VOL, 0x50
	.byte N06
	.byte Cn1
	.byte v080
	.byte W24
	.byte Dn1
	.byte W24
	.byte Cn1
	.byte W24
	.byte Dn1
	.byte W24
mus_shinka_3_86BD7B4: @ 86BD7B4
	.byte N06
	.byte Cn1
	.byte v080
	.byte W24
	.byte Dn1
	.byte W24
	.byte Cn1
	.byte W24
	.byte N24
	.byte Dn1
	.byte W24
	.byte PEND
	.byte N06
	.byte Cn1
	.byte W24
	.byte Dn1
	.byte W24
	.byte Cn1
	.byte W24
	.byte Dn1
	.byte W24
	.byte PATT
	.word mus_shinka_3_86BD7B4
mus_shinka_3_86BD7CE: @ 86BD7CE
	.byte N03
	.byte Cn2
	.byte v080
	.byte W12
	.byte Cn1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Dn2
	.byte W12
	.byte Dn1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Cn2
	.byte W12
	.byte Cn1
	.byte W06
	.byte Gn1
	.byte W06
	.byte Dn2
	.byte W12
	.byte Dn1
	.byte W06
	.byte Gn1
	.byte W06
	.byte PEND
	.byte PATT
	.word mus_shinka_3_86BD7CE
	.byte PATT
	.word mus_shinka_3_86BD7CE
	.byte PATT
	.word mus_shinka_3_86BD7CE
mus_shinka_3_86BD7F8: @ 86BD7F8
	.byte N03
	.byte Dn2
	.byte v080
	.byte W12
	.byte Dn1
	.byte W06
	.byte An1
	.byte W06
	.byte En2
	.byte W12
	.byte En1
	.byte W06
	.byte An1
	.byte W06
	.byte Dn2
	.byte W12
	.byte Dn1
	.byte W06
	.byte An1
	.byte W06
	.byte En2
	.byte W12
	.byte En1
	.byte W06
	.byte An1
	.byte W06
	.byte PEND
	.byte PATT
	.word mus_shinka_3_86BD7F8
	.byte PATT
	.word mus_shinka_3_86BD7F8
	.byte PATT
	.word mus_shinka_3_86BD7F8
	.byte PATT
	.word mus_shinka_3_86BD7F8
	.byte PATT
	.word mus_shinka_3_86BD7F8
	.byte PATT
	.word mus_shinka_3_86BD7F8
	.byte PATT
	.word mus_shinka_3_86BD7F8
	.byte GOTO
	.word mus_shinka_3_86BD7F8
	.byte FINE

mus_shinka_4: @ 86BD83C
	.byte KEYSH, 0x00
	.byte VOICE, 0x2F
	.byte VOL, 0x50
	.byte PAN, 0x3A
	.byte N12
	.byte Cn2
	.byte v112
	.byte W24
	.byte Dn2
	.byte W24
	.byte Cn2
	.byte W24
	.byte Dn2
	.byte W24
	.byte Cn2
	.byte W24
	.byte Dn2
	.byte W24
	.byte Cn2
	.byte W12
	.byte N12
	.byte W12
	.byte N06
	.byte Dn2
	.byte v127
	.byte W06
	.byte Dn2
	.byte v108
	.byte W06
	.byte Dn2
	.byte v112
	.byte W06
	.byte Dn2
	.byte v120
	.byte W06
	.byte N12
	.byte Cn2
	.byte v112
	.byte W24
	.byte Dn2
	.byte W24
	.byte Cn2
	.byte W24
	.byte Dn2
	.byte W24
	.byte Cn2
	.byte W24
	.byte Dn2
	.byte W24
	.byte Cn2
	.byte W24
	.byte N06
	.byte Dn2
	.byte v127
	.byte W06
	.byte Dn2
	.byte v108
	.byte W06
	.byte Dn2
	.byte v112
	.byte W06
	.byte Dn2
	.byte v120
	.byte W06
mus_shinka_4_86BD880: @ 86BD880
	.byte N12
	.byte Cn2
	.byte v112
	.byte W24
	.byte Dn2
	.byte W24
	.byte Cn2
	.byte W24
	.byte Dn2
	.byte W12
	.byte N12
	.byte W12
	.byte PEND
mus_shinka_4_86BD88D: @ 86BD88D
	.byte N12
	.byte Cn2
	.byte v112
	.byte W24
	.byte Dn2
	.byte W18
	.byte N06
	.byte W06
	.byte N12
	.byte Cn2
	.byte W24
	.byte N06
	.byte Dn2
	.byte v127
	.byte W06
	.byte Dn2
	.byte v108
	.byte W06
	.byte Dn2
	.byte v112
	.byte W06
	.byte Dn2
	.byte v120
	.byte W06
	.byte PEND
	.byte PATT
	.word mus_shinka_4_86BD880
	.byte PATT
	.word mus_shinka_4_86BD88D
mus_shinka_4_86BD8B0: @ 86BD8B0
	.byte N12
	.byte Dn2
	.byte v112
	.byte W24
	.byte En2
	.byte W24
	.byte Dn2
	.byte W24
	.byte En2
	.byte W12
	.byte N12
	.byte W12
	.byte PEND
mus_shinka_4_86BD8BD: @ 86BD8BD
	.byte N12
	.byte Dn2
	.byte v112
	.byte W24
	.byte En2
	.byte W18
	.byte N06
	.byte W06
	.byte N12
	.byte Dn2
	.byte W24
	.byte N06
	.byte En2
	.byte v127
	.byte W06
	.byte En2
	.byte v108
	.byte W06
	.byte En2
	.byte v112
	.byte W06
	.byte En2
	.byte v120
	.byte W06
	.byte PEND
	.byte PATT
	.word mus_shinka_4_86BD8B0
mus_shinka_4_86BD8DB: @ 86BD8DB
	.byte N15
	.byte Dn2
	.byte v112
	.byte W24
	.byte N12
	.byte En2
	.byte W18
	.byte N06
	.byte W06
	.byte N12
	.byte Dn2
	.byte W24
	.byte N06
	.byte En2
	.byte v127
	.byte W06
	.byte En2
	.byte v108
	.byte W06
	.byte En2
	.byte v112
	.byte W06
	.byte En2
	.byte v120
	.byte W06
	.byte PEND
	.byte PATT
	.word mus_shinka_4_86BD8B0
	.byte PATT
	.word mus_shinka_4_86BD8DB
	.byte PATT
	.word mus_shinka_4_86BD8B0
	.byte PATT
	.word mus_shinka_4_86BD8BD
	.byte GOTO
	.word mus_shinka_4_86BD8B0
	.byte FINE

mus_shinka_5: @ 86BD90F
	.byte KEYSH, 0x00
	.byte VOICE, 0x53
	.byte PAN, 0x11
	.byte XCMD, 0x08
	.byte AsM2
	.byte v009
	.byte GsM2
	.byte VOL, 0x50
	.byte N06
	.byte Cn3
	.byte v056
	.byte W24
	.byte Dn3
	.byte v032
	.byte W24
	.byte Cn3
	.byte v036
	.byte W24
	.byte Dn3
	.byte v040
	.byte W24
mus_shinka_5_86BD929: @ 86BD929
	.byte N06
	.byte Cn3
	.byte v044
	.byte W24
	.byte Dn3
	.byte v048
	.byte W24
	.byte Cn3
	.byte v052
	.byte W24
	.byte N24
	.byte Dn3
	.byte v056
	.byte W24
	.byte PEND
mus_shinka_5_86BD938: @ 86BD938
	.byte N06
	.byte Cn3
	.byte v056
	.byte W24
	.byte Dn3
	.byte v032
	.byte W24
	.byte Cn3
	.byte v036
	.byte W24
	.byte Dn3
	.byte v040
	.byte W24
	.byte PEND
	.byte PATT
	.word mus_shinka_5_86BD929
	.byte PATT
	.word mus_shinka_5_86BD938
	.byte PATT
	.word mus_shinka_5_86BD929
	.byte PATT
	.word mus_shinka_5_86BD938
	.byte PATT
	.word mus_shinka_5_86BD929
mus_shinka_5_86BD95F: @ 86BD95F
	.byte N06
	.byte Dn3
	.byte v056
	.byte W24
	.byte En3
	.byte v032
	.byte W24
	.byte Dn3
	.byte v036
	.byte W24
	.byte En3
	.byte v040
	.byte W24
	.byte PEND
mus_shinka_5_86BD96D: @ 86BD96D
	.byte N06
	.byte Dn3
	.byte v044
	.byte W24
	.byte En3
	.byte v048
	.byte W24
	.byte Dn3
	.byte v052
	.byte W24
	.byte N24
	.byte En3
	.byte v056
	.byte W24
	.byte PEND
	.byte PATT
	.word mus_shinka_5_86BD95F
	.byte PATT
	.word mus_shinka_5_86BD96D
	.byte PATT
	.word mus_shinka_5_86BD95F
	.byte PATT
	.word mus_shinka_5_86BD96D
	.byte PATT
	.word mus_shinka_5_86BD95F
	.byte PATT
	.word mus_shinka_5_86BD96D
	.byte GOTO
	.word mus_shinka_5_86BD95F
	.byte FINE

mus_shinka_6: @ 86BD9A0
	.byte KEYSH, 0x00
	.byte VOICE, 0x54
	.byte XCMD, 0x08
	.byte AsM2
	.byte v009
	.byte GsM2
	.byte PAN, 0x70
	.byte VOL, 0x50
	.byte BEND, 0x40
	.byte N06
	.byte An2
	.byte v056
	.byte W24
	.byte Bn2
	.byte v032
	.byte W24
	.byte An2
	.byte v036
	.byte W24
	.byte Bn2
	.byte v040
	.byte W24
mus_shinka_6_86BD9BC: @ 86BD9BC
	.byte N06
	.byte An2
	.byte v044
	.byte W24
	.byte Bn2
	.byte v048
	.byte W24
	.byte An2
	.byte v052
	.byte W24
	.byte N24
	.byte Bn2
	.byte v056
	.byte W24
	.byte PEND
mus_shinka_6_86BD9CB: @ 86BD9CB
	.byte N06
	.byte An2
	.byte v056
	.byte W24
	.byte Bn2
	.byte v032
	.byte W24
	.byte An2
	.byte v036
	.byte W24
	.byte Bn2
	.byte v040
	.byte W24
	.byte PEND
	.byte PATT
	.word mus_shinka_6_86BD9BC
	.byte PATT
	.word mus_shinka_6_86BD9CB
	.byte PATT
	.word mus_shinka_6_86BD9BC
	.byte PATT
	.word mus_shinka_6_86BD9CB
	.byte PATT
	.word mus_shinka_6_86BD9BC
mus_shinka_6_86BD9F2: @ 86BD9F2
	.byte N06
	.byte Bn2
	.byte v056
	.byte W24
	.byte Cs3
	.byte v032
	.byte W24
	.byte Bn2
	.byte v036
	.byte W24
	.byte Cs3
	.byte v040
	.byte W24
	.byte PEND
mus_shinka_6_86BDA00: @ 86BDA00
	.byte N06
	.byte Bn2
	.byte v044
	.byte W24
	.byte Cs3
	.byte v048
	.byte W24
	.byte Bn2
	.byte v052
	.byte W24
	.byte N24
	.byte Cs3
	.byte v056
	.byte W24
	.byte PEND
	.byte PATT
	.word mus_shinka_6_86BD9F2
	.byte PATT
	.word mus_shinka_6_86BDA00
	.byte PATT
	.word mus_shinka_6_86BD9F2
	.byte PATT
	.word mus_shinka_6_86BDA00
	.byte PATT
	.word mus_shinka_6_86BD9F2
	.byte PATT
	.word mus_shinka_6_86BDA00
	.byte GOTO
	.word mus_shinka_6_86BD9F2
	.byte FINE

mus_shinka_7: @ 86BDA33
	.byte VOL, 0x50
	.byte KEYSH, 0x00
	.byte VOICE, 0x00
	.byte PAN, 0x40
	.byte N06
	.byte En1
	.byte v112
	.byte W24
	.byte N06
	.byte W24
	.byte N06
	.byte W24
	.byte N06
	.byte W24
	.byte N06
	.byte W24
	.byte N06
	.byte W24
	.byte N03
	.byte W03
	.byte En1
	.byte v068
	.byte W03
	.byte N03
	.byte W03
	.byte En1
	.byte v064
	.byte W03
	.byte N03
	.byte W03
	.byte En1
	.byte v068
	.byte W03
	.byte N03
	.byte W03
	.byte En1
	.byte v064
	.byte W03
	.byte En1
	.byte v112
	.byte W03
	.byte En1
	.byte v072
	.byte W03
	.byte En1
	.byte v076
	.byte W03
	.byte En1
	.byte v088
	.byte W03
	.byte N03
	.byte W03
	.byte En1
	.byte v096
	.byte W03
	.byte En1
	.byte v100
	.byte W03
	.byte En1
	.byte v112
	.byte W03
	.byte N06
	.byte W12
	.byte En1
	.byte v080
	.byte W12
	.byte En1
	.byte v112
	.byte W12
	.byte En1
	.byte v080
	.byte W12
	.byte En1
	.byte v112
	.byte W12
	.byte En1
	.byte v080
	.byte W12
	.byte En1
	.byte v112
	.byte W12
	.byte N06
	.byte W06
	.byte N06
	.byte W06
	.byte N06
	.byte W12
	.byte En1
	.byte v080
	.byte W12
	.byte En1
	.byte v112
	.byte W12
	.byte En1
	.byte v080
	.byte W12
	.byte En1
	.byte v112
	.byte W12
	.byte En1
	.byte v080
	.byte W12
	.byte N03
	.byte En1
	.byte v127
	.byte W03
	.byte En1
	.byte v088
	.byte W03
	.byte En1
	.byte v096
	.byte W03
	.byte En1
	.byte v104
	.byte W03
	.byte En1
	.byte v108
	.byte W03
	.byte En1
	.byte v112
	.byte W03
	.byte En1
	.byte v116
	.byte W03
	.byte En1
	.byte v120
	.byte W03
	.byte N06
	.byte En1
	.byte v127
	.byte W12
	.byte En1
	.byte v100
	.byte W12
	.byte En1
	.byte v127
	.byte W12
	.byte En1
	.byte v096
	.byte W12
	.byte En1
	.byte v127
	.byte W12
	.byte En1
	.byte v096
	.byte W12
	.byte En1
	.byte v127
	.byte W12
	.byte N06
	.byte W06
	.byte N06
	.byte W06
	.byte N06
	.byte W12
	.byte En1
	.byte v100
	.byte W12
	.byte En1
	.byte v127
	.byte W12
	.byte En1
	.byte v096
	.byte W12
	.byte En1
	.byte v127
	.byte W12
	.byte En1
	.byte v096
	.byte W12
	.byte N03
	.byte En1
	.byte v127
	.byte W03
	.byte En1
	.byte v088
	.byte W03
	.byte En1
	.byte v096
	.byte W03
	.byte En1
	.byte v104
	.byte W03
	.byte En1
	.byte v108
	.byte W03
	.byte En1
	.byte v112
	.byte W03
	.byte En1
	.byte v116
	.byte W03
	.byte En1
	.byte v120
	.byte W03
mus_shinka_7_86BDAFA: @ 86BDAFA
	.byte N06
	.byte En1
	.byte v127
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v100
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v127
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v096
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v127
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v096
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v127
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v127
	.byte W06
	.byte N06
	.byte W06
	.byte PEND
mus_shinka_7_86BDB2B: @ 86BDB2B
	.byte N06
	.byte En1
	.byte v127
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v100
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v127
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v096
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v127
	.byte W06
	.byte En1
	.byte v036
	.byte W06
	.byte En1
	.byte v096
	.byte W06
	.byte En1
	.byte v127
	.byte W06
	.byte N03
	.byte W03
	.byte En1
	.byte v088
	.byte W03
	.byte En1
	.byte v096
	.byte W03
	.byte En1
	.byte v104
	.byte W03
	.byte En1
	.byte v108
	.byte W03
	.byte En1
	.byte v112
	.byte W03
	.byte En1
	.byte v116
	.byte W03
	.byte En1
	.byte v120
	.byte W03
	.byte PEND
mus_shinka_7_86BDB68: @ 86BDB68
	.byte PATT
	.word mus_shinka_7_86BDAFA
	.byte PATT
	.word mus_shinka_7_86BDB2B
	.byte PATT
	.word mus_shinka_7_86BDAFA
	.byte PATT
	.word mus_shinka_7_86BDB2B
	.byte PATT
	.word mus_shinka_7_86BDAFA
	.byte PATT
	.word mus_shinka_7_86BDB2B
	.byte PATT
	.word mus_shinka_7_86BDAFA
	.byte PATT
	.word mus_shinka_7_86BDB2B
	.byte GOTO
	.word mus_shinka_7_86BDB68
	.byte FINE

@ ***************************************
	.align 2
mus_shinka: @ 86BDB98
	.byte 7
	.byte 0
	.byte mus_shinka_pri
	.byte mus_shinka_rev
	.word mus_shinka_grp

	.word mus_shinka_1
	.word mus_shinka_2
	.word mus_shinka_3
	.word mus_shinka_4
	.word mus_shinka_5
	.word mus_shinka_6
	.word mus_shinka_7
