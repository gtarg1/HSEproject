#pragma once
#include <QObject>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Source/Entity/playlist.h"
#include "Source/Entity/trackInfo.h"

class CSVModel : public QObject
{
    Q_OBJECT
public:
    CSVModel() = default;
    ~CSVModel() = default;
signals:
    void updateSignal(const std::vector<TrackInfo>& infos);
    void addSignal();
    void removeSignal();
    void editSignal();

    void addPlaylist(const std::vector<Playlist>& playlists);
    void showAdditionalInfoPlayList(Playlist playlist);

public:
    void modelParseSong(const std::string& filename);
    void modelAddSong(TrackInfo info);
    void modelRemoveSong(int index);
    void modelSaveSong(const std::string& filename);

    void modelAddPlaylist(Playlist playlist);
    void modelAdditionalPlaylistInfo(int index);
    void modelRemovePlaylist(const std::vector<int>& indecies);

    void modelSavePlaylist(const std::string& filename);

private:
    std::vector<TrackInfo> infos_;
    std::vector<Playlist> playlists_;
};