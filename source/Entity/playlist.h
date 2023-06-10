#pragma once
#include "trackInfo.h"
#include <QObject>
#include <vector>
class Playlist
{
public:
    Playlist(const std::string& name, const std::string& description, long long duration, const std::vector<TrackInfo>& infos);
    ~Playlist() = default;
    std::string getName() const;
    std::string getDescription() const;
    long long getDuration() const;
    std::vector<TrackInfo> getInfos() const;

private:
    std::string name_;
    std::string description_;
    long long duration_;
    std::vector<TrackInfo> infos_;
};
