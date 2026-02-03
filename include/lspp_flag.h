#pragma once
using u32 = unsigned int;

enum lspp_flag : u32 {
	None		   = 0,
	Reversed	   = 1 << 0,
	TypeReversed   = 1 << 1,
	CaseSensitive  = 1 << 2,
	RecursiveSize  = 1 << 3,
};