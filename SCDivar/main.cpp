#include "memory.h"
#include <thread>
#include <array>
#include <iostream>

namespace offset
{
	//cliente
	constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDEA964;
	constexpr ::std::ptrdiff_t dwEntityList = 0x4DFFEF4;
	constexpr ::std::ptrdiff_t dwClientState = 0x59F19C;

	//jugador
	constexpr ::std::ptrdiff_t m_hMyWeapons = 0x2E08;

	//base atribuible
	constexpr ::std::ptrdiff_t m_flFallbackWear = 0x31E0;
	constexpr ::std::ptrdiff_t m_nFallbackPaintKit = 0x31D8;
	constexpr ::std::ptrdiff_t m_nFallbackSeed = 0x31DC;
	constexpr ::std::ptrdiff_t m_nFallbackStatTrak = 0x31E4;
	constexpr ::std::ptrdiff_t m_iItemDefinitionIndex = 0x2FBA;
	constexpr ::std::ptrdiff_t m_iItemIDHigh = 0x2FD0;
	constexpr ::std::ptrdiff_t m_iEntityQuality = 0x2FBC;
	constexpr ::std::ptrdiff_t m_iAccountID = 0x2FD8;
	constexpr ::std::ptrdiff_t m_OriginalOwnerXuidLow = 0x31D0;

}

//definir ID de las skins
constexpr const int GetWeaponPaint(const short& itemDefinition)
{
	switch (itemDefinition)
	{
	//case 5028: return 5030; //guantes prueba
	//case 5029: return 5030; //guantes prueba

	case 1: return 764;  //deagle
	case 4: return 988;  //glock
	case 7: return 959;  //ak
	case 9: return 756;  //awp
	case 61: return 504; //usp
	case 60: return 946; //m4a4-s
	case 17: return 898; //MAC
	case 34: return 1134; //mp9

	//case 42: return 38;  //poli cuchillo
	//case 59: return 38;  //terro cuchillo

	default: return 0;
	}
}

int main()
{
	const auto memory = Memory{ "csgo.exe" };
	
	//conseguir la direccion
	const auto client = memory.GetModuleAddress("client.dll");
	const auto engine = memory.GetModuleAddress("engine.dll");

	//bucle main
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2));

		const auto& localPlayer = memory.Read<std::uintptr_t>(client + offset::dwLocalPlayer);
		const auto& weapons = memory.Read<std::array<unsigned long, 8>>(localPlayer + offset::m_hMyWeapons);

		//jugador local interaccion de arma
		for (const auto& handle : weapons)
		{
			const auto& weapon = memory.Read<std::uintptr_t>((client + offset::dwEntityList + (handle & 0xFFF) * 0x10) - 0x10);

			//crear una arma valida
			if (!weapon)
				continue;

			//see if we want to apply a skin
			if (const auto paint = GetWeaponPaint(memory.Read<short>(weapon + offset::m_iItemDefinitionIndex)))
			{
				const bool shouldUpdate = memory.Read<std::int32_t>(weapon + offset::m_nFallbackPaintKit) != paint;
				
				//forzar al arna a usar valor de fallback
				memory.Write<std::int32_t>(weapon + offset::m_iItemIDHigh, -1);

				memory.Write<std::int32_t>(weapon + offset::m_nFallbackPaintKit, paint);
				memory.Write<float>(weapon + offset::m_flFallbackWear, 0.12f);

				if (shouldUpdate)
					memory.Write<std::int32_t>(memory.Read<std::uintptr_t>(engine + offset::dwClientState) + 0x174, -1);
					std::cout << "csgo reset - Riesgo de BAN \n ";
			}
		}

	}

	return 0;
}