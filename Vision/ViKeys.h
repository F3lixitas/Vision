/*
ViKeys.h
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This file associates keycodes to macros.
*/


#ifndef VI_KEYS
#define VI_KEYS

#ifdef _WIN32
#define VI_A_AZERTY 65
#define VI_Z_AZERTY 90
#define VI_E_AZERTY 69
#define VI_R_AZERTY 82
#define VI_T_AZERTY 84
#define VI_Y_AZERTY 89
#define VI_U_AZERTY 85
#define VI_I_AZERTY 73
#define VI_O_AZERTY 79
#define VI_P_AZERTY 80
#define VI_Q_AZERTY 81
#define VI_S_AZERTY 83
#define VI_D_AZERTY 68
#define VI_F_AZERTY 70
#define VI_G_AZERTY 71
#define VI_H_AZERTY 72
#define VI_J_AZERTY 74
#define VI_K_AZERTY 75
#define VI_L_AZERTY 76
#define VI_M_AZERTY 77
#define VI_W_AZERTY 87
#define VI_X_AZERTY 88
#define VI_C_AZERTY 67
#define VI_V_AZERTY 86
#define VI_B_AZERTY 66
#define VI_N_AZERTY 78

#elif defined __linux__
#define VI_ALT_AZERTY 64

#define VI_A_AZERTY 24
#define VI_Z_AZERTY 25
#define VI_E_AZERTY 26
#define VI_R_AZERTY 27
#define VI_T_AZERTY 28
#define VI_Y_AZERTY 29
#define VI_U_AZERTY 30
#define VI_I_AZERTY 31
#define VI_O_AZERTY 32
#define VI_P_AZERTY 33
#define VI_Q_AZERTY 38
#define VI_S_AZERTY 39
#define VI_D_AZERTY 40
#define VI_F_AZERTY 41
#define VI_G_AZERTY 42
#define VI_H_AZERTY 43
#define VI_J_AZERTY 44
#define VI_K_AZERTY 45
#define VI_L_AZERTY 46
#define VI_M_AZERTY 47
#define VI_W_AZERTY 52
#define VI_X_AZERTY 53
#define VI_C_AZERTY 54
#define VI_V_AZERTY 55
#define VI_B_AZERTY 56
#define VI_N_AZERTY 57

#endif


#endif