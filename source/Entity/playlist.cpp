#include "playlist.h"

Playlist::Playlist(const std::string& name, const std::string& description, long long duration, const std::vector<TrackInfo>& infos)
    : name_(name), description_(description), duration_(duration), infos_(infos)
{
}

std::string Playlist::getName() const
{
    return name_;
}

std::string Playlist::getDescription() const
{
    return description_;
}

long long Playlist::getDuration() const
{
    return duration_;
}

std::vector<TrackInfo> Playlist::getInfos() const
{
    return infos_;
}
