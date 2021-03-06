﻿// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef _DEBUG

/*********************************/
/**    BEGIN Debug Libraries    **/
/*********************************/
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#pragma comment(lib,"dlib-d.lib")
/*********************************/
/**     END Debug Libraries     **/
/*********************************/

#else

/*********************************/
/**   BEGIN Release Libraries   **/
/*********************************/
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#pragma comment(lib,"dlib.lib")
/*********************************/
/**    END Release Libraries    **/
/*********************************/

#endif

/*********************************/
/** BEGIN Independant Libraries **/
/*********************************/
/*********************************/
/**  END Independant Libraries  **/
/*********************************/

// STL Common C libraries
#include <cstddef>
#include <cstdint>

// STL Containers
#include <iterator>
#include <array>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

// STL Utility libraries
#include <exception>
#include <type_traits>
#include <memory>
#include <random>
#include <chrono>
#include <functional>
#include <tuple>
#include <initializer_list>
#include <limits>
#include <variant>
#include <optional>

// STL Input/Output libraries
#include <string>
#include <sstream>
#include <istream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <filesystem>

// STL Multithreading libraries
#include <thread>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <future>
#include <condition_variable>

// SFML
#include <SFML/Main.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/GpuPreference.hpp>
#include <SFML/Graphics.hpp>

// Modern Json
#include <Js/json.hpp>

// Entt
#include <Entt/entt.hpp>

// Dlib Neural Network
#include <dlib/mlp.h>

/*********************************/
/**         Includes here       **/
/*********************************/

#include <src/math/Vector2.h>

#include <src/input/Keyhandler.h>
#include <src/input/MouseHandler.h>

#include <src/utilities/Console.h>

// Global namespace
namespace app
{
	typedef std::uint64_t Entity;
	typedef entt::Registry<Entity> Registry;
	namespace inp
	{
		typedef sf::Keyboard::Key KeyCode;
		typedef app::inp::Keyhandler<KeyCode> KeyHandler;
		typedef sf::Mouse::Button ButtonCode;
		typedef app::inp::Mousehandler<ButtonCode> MouseHandler;
	}
}
