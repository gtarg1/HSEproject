#include "CSVModel.h"

bool to_bool(std::string str)
{
    if (str == "True")
        return true;
    return false;
}

void CSVModel::modelParseSong(const std::string& filename)
{
    std::ifstream csvFile(filename);
    std::vector<TrackInfo> infos;

    std::string line;
    int i = 0;
    while (std::getline(csvFile, line))
    {
        if (i++ == 0)
        {
            continue;
        }

        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> cells;

        bool isQuote = false;
        std::string helpstr = "";
        while (std::getline(ss, cell, ','))
        {
            if (!helpstr.empty() && helpstr[helpstr.length() - 1] == '\"')
            {
                isQuote = false;
                cells.push_back(helpstr);
                cells.push_back(cell);

                helpstr = "";
                continue;
            }
            if (isQuote)
            {
                helpstr += cell;
                continue;
            }

            if (cell[0] == '\"')
            {
                isQuote = true;
                helpstr += cell;
                continue;
            }
            cells.push_back(cell);
        }
        if (cells.size() == 17)
        {
            cells.push_back(helpstr);
        }

        TrackInfo info(cells[0], cells[1], std::stoi(cells[2]),
                       to_bool(cells[3]), std::stoll(cells[4]), std::stoll(cells[5]),
                       std::stof(cells[6]), std::stof(cells[7]), std::stoll(cells[8]),
                       std::stof(cells[9]), to_bool(cells[10]), std::stof(cells[11]),
                       std::stof(cells[12]), std::stof(cells[13]), std::stof(cells[14]),
                       std::stof(cells[15]), std::stoll(cells[16]),
                       cells[17]);
        infos.push_back(info);
    }
    infos_ = infos;
    emit updateSignal(infos);
};

void CSVModel::modelAddSong(TrackInfo info)
{
    infos_.push_back(info);
    emit updateSignal(infos_);
}

void CSVModel::modelRemoveSong(int index)
{
    infos_.erase((infos_.begin() + index));
    emit updateSignal(infos_);
}


void CSVModel::modelSaveSong(const std::string& filename)
{
    std::ofstream out(filename);
    if (out.is_open())
    {
        out << "artist,song,duration_ms,explicit,year,popularity,danceability,energy,key,loudness,mode,speechiness,acousticness,instrumentalness,liveness,valence,tempo,genre\n";
        if (infos_.size() != 0)
        {
            for (int i = 0; i < infos_.size(); ++i)
            {
                out << infos_[i].getArtist() << ',' << infos_[i].getSong() << ',' << infos_[i].getDuration() << ',' << infos_[i].isExplicit() << ',' << infos_[i].getYear() << ',' << infos_[i].getPopularity() << ',' << infos_[i].getDanceability() << ',' << infos_[i].getEnergy() << ',' << infos_[i].getKey() << ',' << infos_[i].getLoudness() << ',' << infos_[i].getMode() << ',' << infos_[i].getSpeechiness() << ',' << infos_[i].getAcousticness() << ',' << infos_[i].getInstrumentalness() << ',' << infos_[i].getLiveness() << ',' << infos_[i].getValence() << ',' << infos_[i].getTempo() << ',' << infos_[i].getGenre() << '\n';
            }
        }
    }
}

void CSVModel::modelAddPlaylist(Playlist playlist)
{
    playlists_.push_back(playlist);
    emit addPlaylist(playlists_);
}

void CSVModel::modelAdditionalPlaylistInfo(int index)
{
    if (index < 0)
    {
        return;
    }
    emit showAdditionalInfoPlayList(playlists_[index]);
}

void CSVModel::modelRemovePlaylist(const std::vector<int>& indecies)
{
    for (int i = 0; i < indecies.size(); ++i)
    {
        playlists_.erase(playlists_.begin() + indecies[i]);
    }
    playlists_;
    emit addPlaylist(playlists_);
}

void CSVModel::modelSavePlaylist(const std::string& filename)
{
    std::ofstream out(filename);
    if (out.is_open())
    {
        if (playlists_.size() != 0)
        {
            for (int i = 0; i < playlists_.size(); ++i)
            {
                out << "{ \n\tName: " << playlists_[i].getName() << ", Descripition: " << playlists_[i].getDescription() << ", Duration: " << playlists_[i].getDuration() << ", \n\tTracks:[\n";
                for (int j = 0; j < playlists_[i].getInfos().size(); j++)
                {
                    out << "\t{ Artist: " << playlists_[i].getInfos()[j].getArtist();
                    out << ", Song: " << playlists_[i].getInfos()[j].getSong();
                    out << ", Duration: " << playlists_[i].getInfos()[j].getDuration();
                    out << ", Explicit: " << (playlists_[i].getInfos()[j].isExplicit());
                    out << ", Year: " << playlists_[i].getInfos()[j].getYear();
                    out << ", Popularity: " << playlists_[i].getInfos()[j].getPopularity();
                    out << ", Danceability: " << playlists_[i].getInfos()[j].getDanceability();
                    out << ", Energy: " << playlists_[i].getInfos()[j].getEnergy();
                    out << ", Key: " << playlists_[i].getInfos()[j].getKey();
                    out << ", Loudness: " << playlists_[i].getInfos()[j].getLoudness();
                    out << ", Mode: " << (playlists_[i].getInfos()[j].getMode());
                    out << ", Speechiness: " << playlists_[i].getInfos()[j].getSpeechiness();
                    out << ", Acousticness: " << playlists_[i].getInfos()[j].getAcousticness();
                    out << ", Instrumentalness: " << playlists_[i].getInfos()[j].getInstrumentalness();
                    out << ", Liveness: " << playlists_[i].getInfos()[j].getLiveness();
                    out << ", Valence: " << playlists_[i].getInfos()[j].getValence();
                    out << ", Tempo: " << playlists_[i].getInfos()[j].getTempo();
                    out << ", Genre: " << playlists_[i].getInfos()[j].getGenre() << " },";
                    out << '\n';
                }
                out << "\t]\n}\n\n";
            }
        }
    }
}
