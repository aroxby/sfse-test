#include <SFSE/SFSE.h>

// Removes CommonLibSF's `inline` so that the symbol will export
#define My_SFSEPluginVersion extern "C" [[maybe_unused]] __declspec(dllexport) constinit SFSE::PluginVersionData SFSEPlugin_Version

namespace Plugin
{
    using namespace std::string_view_literals;

    static constexpr auto Name{ "sfse-test"sv };
    static constexpr auto Author{ "aroxby"sv };
    static constexpr auto Version{
        REL::Version{0, 0, 0, 0}
    };
}

My_SFSEPluginVersion = []() noexcept {
    SFSE::PluginVersionData data{};

    data.PluginVersion(Plugin::Version.pack());
    data.PluginName(Plugin::Name);
    data.AuthorName(Plugin::Author);
    data.UsesAddressLibrary(true);
    data.IsLayoutDependent(true);
    data.CompatibleVersions({ SFSE::RUNTIME_LATEST });

    return data;
}();

SFSEPluginLoad(const SFSE::LoadInterface *sfse) {
    Init(sfse);
    // My Games\Starfield\SFSE\Logs
    SFSE::log::info("sfse-test loaded");
    return true;
}
