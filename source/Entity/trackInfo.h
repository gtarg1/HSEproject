#pragma once
#include <string>

class TrackInfo
{
public:
    TrackInfo(std::string artist = "", std::string song = "", long long duration = 0, bool explicit_ = 0, long long year = 0, long long popularity = 0, float danceability = 0,
              float energy = 0, long long key = 0, float loudness = 0, bool mode = 0, float speechines = 0, float acousticness = 0, float instrumentalness = 0,
              float liveness = 0, float valence = 0, long long tempo = 0, std::string genre = 0);
    ~TrackInfo() = default;

public:
    std::string getArtist() const;

    std::string getSong() const;

    long long getDuration() const;

    bool isExplicit() const;

    long long getYear() const;

    long long getPopularity() const;

    float getDanceability() const;

    float getEnergy() const;

    long long getKey() const;

    float getLoudness() const;

    bool getMode() const;

    float getSpeechiness() const;

    float getAcousticness() const;

    float getInstrumentalness() const;

    float getLiveness() const;

    float getValence() const;

    long long getTempo() const;

    std::string getGenre() const;

    void setArtist(const std::string& artist);

    void setSong(const std::string& song);

    void setDuration(long long duration);

    void setExplicit(bool explicit_);

    void setYear(long long year);

    void setPopularity(long long popularity);

    void setDanceability(float danceability);

    void setEnergy(float energy);

    void setKey(long long key);

    void setLoudness(float loudness);

    void setMode(bool mode);

    void setSpeechiness(float speechines);

    void setAcousticness(float acousticness);

    void setInstrumentalness(float instrumentalness);

    void setLiveness(float liveness);

    void setValence(float valence);

    void setTempo(long long tempo);

    void setGenre(const std::string& genre);

private:
    std::string artist_;
    std::string song_;
    long long duration_;
    bool explicit_;
    long long year_;
    long long popularity_;
    float danceability_;
    float energy_;
    long long key_;
    float loudness_;
    bool mode_;
    float speechines_;
    float acousticness_;
    float instrumentalness_;
    float liveness_;
    float valence_;
    long long tempo_;
    std::string genre_;
};