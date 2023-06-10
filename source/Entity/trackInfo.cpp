#include "trackInfo.h"
#include <string>


TrackInfo::TrackInfo(std::string artist, std::string song, long long duration, bool explicit_,
                     long long year, long long popularity, float danceability, float energy, long long key, float loudness,
                     bool mode, float speechines, float acousticness, float instrumentalness, float liveness,
                     float valence, long long tempo, std::string genre) : artist_(artist),
                                                                          song_(song), duration_(duration), explicit_(explicit_), year_(year), popularity_(popularity),
                                                                          danceability_(danceability), energy_(energy), key_(key), loudness_(loudness), mode_(mode),
                                                                          speechines_(speechines), acousticness_(acousticness), instrumentalness_(instrumentalness),
                                                                          liveness_(liveness), valence_(valence), tempo_(tempo), genre_(genre)
{
}

std::string TrackInfo::getArtist() const
{
    return artist_;
}

std::string TrackInfo::getSong() const
{
    return song_;
}

long long TrackInfo::getDuration() const
{
    return duration_;
}

bool TrackInfo::isExplicit() const
{
    return explicit_;
}

long long TrackInfo::getYear() const
{
    return year_;
}

long long TrackInfo::getPopularity() const
{
    return popularity_;
}

float TrackInfo::getDanceability() const
{
    return danceability_;
}

float TrackInfo::getEnergy() const
{
    return energy_;
}

long long TrackInfo::getKey() const
{
    return key_;
}

float TrackInfo::getLoudness() const
{
    return loudness_;
}

bool TrackInfo::getMode() const
{
    return mode_;
}

float TrackInfo::getSpeechiness() const
{
    return speechines_;
}

float TrackInfo::getAcousticness() const
{
    return acousticness_;
}

float TrackInfo::getInstrumentalness() const
{
    return instrumentalness_;
}

float TrackInfo::getLiveness() const
{
    return liveness_;
}

float TrackInfo::getValence() const
{
    return valence_;
}

long long TrackInfo::getTempo() const
{
    return tempo_;
}

std::string TrackInfo::getGenre() const
{
    return genre_;
}

void TrackInfo::setArtist(const std::string& artist)
{
    artist_ = artist;
}

void TrackInfo::setSong(const std::string& song)
{
    song_ = song;
}

void TrackInfo::setDuration(long long duration)
{
    duration_ = duration;
}

void TrackInfo::setExplicit(bool explicit_)
{
    explicit_ = explicit_;
}

void TrackInfo::setYear(long long year)
{
    year_ = year;
}

void TrackInfo::setPopularity(long long popularity)
{
    popularity_ = popularity;
}

void TrackInfo::setDanceability(float danceability)
{
    danceability_ = danceability;
}

void TrackInfo::setEnergy(float energy)
{
    energy_ = energy;
}

void TrackInfo::setKey(long long key)
{
    key_ = key;
}

void TrackInfo::setLoudness(float loudness)
{
    loudness_ = loudness;
}

void TrackInfo::setMode(bool mode)
{
    mode_ = mode;
}

void TrackInfo::setSpeechiness(float speechines)
{
    speechines_ = speechines;
}

void TrackInfo::setAcousticness(float acousticness)
{
    acousticness_ = acousticness;
}

void TrackInfo::setInstrumentalness(float instrumentalness)
{
    instrumentalness_ = instrumentalness;
}

void TrackInfo::setLiveness(float liveness)
{
    liveness_ = liveness;
}

void TrackInfo::setValence(float valence)
{
    valence_ = valence;
}

void TrackInfo::setTempo(long long tempo)
{
    tempo_ = tempo;
}

void TrackInfo::setGenre(const std::string& genre)
{
    genre_ = genre;
}
