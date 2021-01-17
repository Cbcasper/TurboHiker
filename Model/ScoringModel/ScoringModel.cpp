//
// Created by Casper De Smet on 08/12/2020.
//

#include "ScoringModel.h"

using namespace std;

namespace turboHiker
{
    ScoringModel::ScoringModel(): playerHikerScore(make_shared<HikerScore>())
    {}

    void ScoringModel::writeScore()
    {
        fstream highScoreFile("../HighScores/highScores.th", ios::app);
        highScoreFile << playerName << " " << timeToText(playerHikerScore->getGameLength()) << endl;
        highScoreFile.close();
    }

    vector<tuple<chrono::milliseconds, string, string>> ScoringModel::readScore()
    {
        fstream highScoreFile("../HighScores/highScores.th");

        vector<tuple<chrono::milliseconds, string, string>> results;

        string readPlayerName;
        string readGameLength;
        while (highScoreFile >> readPlayerName && highScoreFile >> readGameLength)
            results.emplace_back((make_tuple(textToTime(readGameLength), readGameLength, readPlayerName)));

        sort(results.begin(), results.end());
        int resultSize = results.size();
        if (resultSize < 3)
            for (int i = 0; i < 3 - resultSize; ++i)
                results.emplace_back(make_tuple(chrono::milliseconds(0), "/", ""));
        return {results[0], results[1], results[2]};
    }

    void ScoringModel::update(const chrono::milliseconds& gameLength)
    {
        playerHikerScore->setGameLength(gameLength);
    }

    std::string ScoringModel::timeToText(const chrono::milliseconds& gameLength)
    {
        // Get the seconds the time translates to
        int seconds = chrono::duration_cast<chrono::seconds>(gameLength).count();
        // Get the remaining milliseconds
        int remainingMilliseconds = int (gameLength.count() - (seconds * 1000));
        stringstream text;
        text << pad(seconds) << ":" << pad(remainingMilliseconds / 10);
        return text.str();
    }

    std::string ScoringModel::pad(int time)
    {
        // Check whether the time is smaller than 10 and add a zero accordingly
        stringstream text;
        if (time < 10)
            text << '0';
        text << time;
        return text.str();
    }

    void ScoringModel::setPlayerName(const string& newPlayerName)
    {
        playerName = newPlayerName;
    }

    std::chrono::milliseconds ScoringModel::textToTime(const string& text)
    {
        string seconds = text.substr(0, 2);
        string milliseconds = text.substr(3, 2);

        return std::chrono::milliseconds(stoi(seconds) * 1000 + stoi(milliseconds));
    }
}