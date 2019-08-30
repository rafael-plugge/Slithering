#include "stdafx.h"
#include <src/singletons/SettingsSingleton.h>

std::optional<app::Settings const> app::sin::Settings::s_settings = std::nullopt;
