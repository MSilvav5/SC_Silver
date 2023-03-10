#include "memory.h"
#include <thread>
#include <array>
#include <iostream>
#include <chrono>

namespace offset
{
	//cliente
	constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDEA964;
	constexpr ::std::ptrdiff_t dwEntityList = 0x4DFFEF4;
	constexpr ::std::ptrdiff_t dwClientState = 0x59F19C;
	constexpr ::std::ptrdiff_t dwClientState_PlayerInfo = 0x52C0;

	//jugador
	constexpr ::std::ptrdiff_t m_hMyWeapons = 0x2E08;

	//prueba
	constexpr ::std::ptrdiff_t dwGameRulesProxy = 0x532F4AC;
	constexpr ::std::ptrdiff_t m_fRoundStartTime = 0x0000004C;

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
	//INICIO DE CONSOLA
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);
	std::string input;
	std::string password = "mamut";

	std::cout << "\n" << std::endl;
	std::cout << "    888    888        d8888  .d8888b.  888    d8P 888     888     d8888 8888888b.  8888888 888     888 888b     d888" << std::endl;
	std::cout << "    888    888       d88888 d88P  Y88b 888   d8P  888     888    d88888 888   Y88b   888   888     888 8888b   d8888" << std::endl;
	std::cout << "    888    888      d88P888 888    888 888  d8P   888     888   d88P888 888    888   888   888     888 88888b.d88888" << std::endl;
	std::cout << "    8888888888     d88P 888 888        888d88K    Y88b   d88P  d88P 888 888   d88P   888   888     888 888Y88888P888" << std::endl;
	std::cout << "    888    888    d88P  888 888        8888888b    Y88b d88P  d88P  888 8888888P     888   888     888 888 Y888P 888" << std::endl;
	std::cout << "    888    888   d88P   888 888    888 888  Y88b    Y88o88P  d88P   888 888 T88b     888   888     888 888  Y8P  888" << std::endl;
	std::cout << "    888    888  d8888888888 Y88b  d88P 888   Y88b    Y888P  d8888888888 888  T88b    888   Y88b..d88P  888       888" << std::endl;
	std::cout << "    888    888 d88P     888   Y8888P   888    Y88b    Y8P  d88P     888 888   T88b 8888888   Y88888P   888       888\n\n\n" << std::endl;

	SetConsoleTextAttribute(h, 12);

	std::cout << "      @@@@@@   @@@  @@@  @@@  @@@  @@@      @@@@@@@  @@@  @@@   @@@@@@   @@@  @@@   @@@@@@@@  @@@@@@@@  @@@@@@@   " << std::endl;
	std::cout << "     @@@@@@@   @@@  @@@  @@@  @@@@ @@@     @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@ @@@  @@@@@@@@@  @@@@@@@@  @@@@@@@@  " << std::endl;
	std::cout << "     !@@       @@!  !@@  @@!  @@!@!@@@     !@@       @@!  @@@  @@!  @@@  @@!@!@@@  !@@        @@!       @@!  @@@  " << std::endl;
	std::cout << "     !@!       !@!  @!!  !@!  !@!!@!@!     !@!       !@!  @!@  !@!  @!@  !@!!@!@!  !@!        !@!       !@!  @!@  " << std::endl;
	std::cout << "     !!@@!!    @!@@!@!   !!@  @!@ !!@!     !@!       @!@!@!@!  @!@!@!@!  @!@ !!@!  !@! @!@!@  @!!!:!    @!@!!@!   " << std::endl;
	std::cout << "      !!@!!!   !!@!!!    !!!  !@!  !!!     !!!       !!!@!!!!  !!!@!!!!  !@!  !!!  !!! !!@!!  !!!!!:    !!@!@!    " << std::endl;
	std::cout << "          !:!  !!: :!!   !!:  !!:  !!!     :!!       !!:  !!!  !!:  !!!  !!:  !!!  :!!   !!:  !!:       !!: :!!   " << std::endl;
	std::cout << "         !:!   :!:  !:!  :!:  :!:  !:!     :!:       :!:  !:!  :!:  !:!  :!:  !:!  :!:   !::  :!:       :!:  !:!  " << std::endl;
	std::cout << "     :::: ::   ::   :::  :::  :::  :::      ::: :::  ::   :::  ::   :::  :::  :::  :::::::::  ::::::::  :::  :::  " << std::endl;
	std::cout << "     :: : :    ::   :::  :::  :::  :::       :: :::  ::   :::  ::   :::  :::  :::   :::::::   ::::::::  :::  :::  " << std::endl;
	
	SetConsoleTextAttribute(h, 7);
	std::cout << "\n\n\n                                     INTRODUZCA LA CONTRASE?A PARA CONTINUAR" << std::endl;
	std::cout << "                                                                                                            version 1.3"<< std::endl;
	
	do {
		std::getline(std::cin, input);
	} while (input != password);

	const auto memory = Memory{ "csgo.exe" };

	//conseguir la direccion
	const auto client = memory.GetModuleAddress("client.dll");
	const auto engine = memory.GetModuleAddress("engine.dll");

	//CODIGO PARA QUE EL BUCLE SE EJECUTE 10 SEGUNDOS
	auto start = std::chrono::steady_clock::now();

	bool roundflag = true;
	bool timerflag = true;
	float prev_roundstart = 0.0;

	//bucle main

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2));

		const auto& localPlayer = memory.Read<std::uintptr_t>(client + offset::dwLocalPlayer);
		const auto& weapons = memory.Read<std::array<unsigned long, 8>>(localPlayer + offset::m_hMyWeapons);

		//SECCION DE PRUEBA
		const auto& gamerules = memory.Read<std::uintptr_t>(client + offset::dwGameRulesProxy);
		const auto& roundstart = memory.Read<float>(gamerules + offset::m_fRoundStartTime);
		std::cout << "FLAG3" << std::endl;

		if (roundflag == true) {
			prev_roundstart = roundstart;
			roundflag = false;
		}

		std::cout << "roudstart: " << roundstart << std::endl;
		std::cout << "prevroudstart: " << prev_roundstart << std::endl;

		if (roundstart > prev_roundstart) {
			if (timerflag == true) {
				start = std::chrono::steady_clock::now();
				timerflag = false;
			}


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

					//forzar al arma a usar valor de fallback
					memory.Write<std::int32_t>(weapon + offset::m_iItemIDHigh, -1);

					memory.Write<std::int32_t>(weapon + offset::m_nFallbackPaintKit, paint);
					memory.Write<float>(weapon + offset::m_flFallbackWear, 0.012f); //desgaste

					if (shouldUpdate)
						memory.Write<std::int32_t>(memory.Read<std::uintptr_t>(engine + offset::dwClientState) + 0x174, -1); //forzado con reset de texturas
					std::cout << "csgo reset" << std::endl;
				}
			}
			auto end = std::chrono::steady_clock::now();
			auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
			std::cout << elapsed_time << std::endl;

			if (elapsed_time >= 10) {
				std::cout << "RESET" << std::endl;
				roundflag = true;
				timerflag = true;

				//reset de temporizador
				start = std::chrono::steady_clock::now();
				end = std::chrono::steady_clock::now();

			}
		}
	}
	std::cout << "salio del bucle" << std::endl;
	return 0;
}