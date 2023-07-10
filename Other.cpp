#include "Other.hpp"

Color color_picker(int i)
{
	switch (i)
	{
	case 0: return Color(204, 192, 179); break;
	case 2: return Color(238, 228, 218); break;
	case 4: return Color(237, 224, 200); break;
	case 8: return Color(242, 177, 121); break;
	case 16: return Color(245, 149, 99); break;
	case 32: return Color(246, 124, 95); break;
	case 64: return Color(246, 94, 59); break;
	case 128: return Color(237, 207, 114); break;
	case 256: return Color(237, 204, 97); break;
	case 512: return Color(237, 200, 80); break;
	case 1024: return Color(237, 197, 63); break;
	case 2048: return Color(237, 194, 46); break;
	default: return Color(0, 0, 0); break;
	}
}