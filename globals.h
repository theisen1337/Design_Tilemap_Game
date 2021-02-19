#pragma once

struct _alphabet
{
	bool pressed;
	float pressed_for_time;
	_alphabet() : pressed(false), pressed_for_time(0.0) {}
};

namespace global
{
	namespace Key
	{
		extern _alphabet A; /* 1 */
		extern _alphabet B;
		extern _alphabet C;
		extern _alphabet D;
		extern _alphabet E;
		extern _alphabet F;
		extern _alphabet G;
		extern _alphabet H;
		extern _alphabet I;
		extern _alphabet J;
		extern _alphabet k;
		extern _alphabet L;
		extern _alphabet M; /* 13 */
		extern _alphabet N;
		extern _alphabet O;
		extern _alphabet P;
		extern _alphabet Q;
		extern _alphabet R;
		extern _alphabet S;
		extern _alphabet T;
		extern _alphabet U;
		extern _alphabet V;
		extern _alphabet W;
		extern _alphabet X;
		extern _alphabet Y;
		extern _alphabet Z; /* 26 */

	}
}