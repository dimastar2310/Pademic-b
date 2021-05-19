#pragma once
#include <string>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <unordered_set>
#include <iostream>

namespace pandemic{

    class Board {
    private:
        std::unordered_map<City, int> disease_rate;
        std::unordered_set<City> research_stations;
        std::unordered_set<Color> cures;

    public:
        Board() {}
        int& operator[](City c);
        bool is_clean();
        void remove_cures();
        friend std::ostream& operator<<(std::ostream& out, const Board& b);
        bool is_research_station(City c);
        void make_research_station(City c);
        void insert_cure(Color c);
        bool cure_exist(Color c);
    };
  //i need City to string
  const std::unordered_map<City,std::string> city_to_string{
          {City::Algiers,       "Algiers"},
          {City::Atlanta,       "Atlanta"},
          {City::Baghdad,       "Baghdad"},
          {City::Bangkok,       "Bangkok"},
          {City::Beijing,       "Beijing"},
          {City::Bogota,        "Bogota"},
          {City::BuenosAires,   "BuenosAires"},
          {City::Cairo,         "Cairo"},
          {City::Chennai,       "Chennai"},
          {City::Chicago,       "Chicago"},
          {City::Delhi,         "Delhi"},
          {City::Essen,         "Essen"},
          {City::HoChiMinhCity, "HoChiMinhCity"},
          {City::HongKong,      "HongKong"},
          {City::Istanbul,      "Istanbul"},
          {City::Jakarta,       "Jakarta"},
          {City::Johannesburg,  "Johannesburg"},
          {City::Karachi,       "Karachi"},
          {City::Khartoum,      "Khartoum"},
          {City::Kinshasa,      "Kinshasa"},
          {City::Kolkata,       "Kolkata"},
          {City::Lagos,         "Lagos"},
          {City::Lima,          "Lima"},
          {City::London,        "London"},
          {City::LosAngeles,    "LosAngeles"},
          {City::Madrid,        "Madrid"},
          {City::Manila,        "Manila"},
          {City::MexicoCity,    "MexicoCity"},
          {City::Miami,         "Miami"},
          {City::Milan,         "Milan"},
          {City::Moscow,        "Moscow"},
          {City::Mumbai,        "Mumbai"},
          {City::NewYork,       "NewYork"},
          {City::Osaka,         "Osaka"},
          {City::Paris,         "Paris"},
          {City::Riyadh,        "Riyadh"},
          {City::SanFrancisco,  "SanFrancisco"},
          {City::Santiago,      "Santiago"},
          {City::SaoPaulo,      "SaoPaulo"},
          {City::Seoul,         "Seoul"},
          {City::Shanghai,      "Shanghai"},
          {City::StPetersburg,  "StPetersburg"},
          {City::Sydney,        "Sydney"},
          {City::Taipei,        "Taipei"},
          {City::Tehran,        "Tehran"},
          {City::Tokyo,         "Tokyo"},
          {City::Washington,    "Washington"}

  };
  //i do have u_m<city,color> need to use it
    const std::unordered_map<Color,std::string> color_to_string{
          {Color::Black,"Black"},{Color::Red,"Red"},{Color::Blue,"Blue"},{Color::Yellow,"Yellow"}
    };
    const std::unordered_map<City, Color> colors_of_cities { //<city,color>
            { City::Algiers, Color::Black },
            { City::Atlanta, Color::Blue },
            { City::Baghdad, Color::Black },
            { City::Bangkok, Color::Red },
            { City::Beijing, Color::Red },
            { City::Bogota, Color::Yellow },
            { City::BuenosAires, Color::Yellow },
            { City::Cairo, Color::Black },
            { City::Chennai, Color::Black },
            { City::Chicago, Color::Blue },
            { City::Delhi, Color::Black },
            { City::Essen, Color::Blue },
            { City::HoChiMinhCity, Color::Red },
            { City::HongKong, Color::Red },
            { City::Istanbul, Color::Black },
            { City::Jakarta, Color::Red },
            { City::Johannesburg, Color::Yellow },
            { City::Karachi, Color::Black },
            { City::Khartoum, Color::Yellow },
            { City::Kinshasa, Color::Yellow },
            { City::Kolkata, Color::Black },
            { City::Lagos, Color::Yellow },
            { City::Lima, Color::Yellow },
            { City::London, Color::Blue },
            { City::LosAngeles, Color::Yellow },
            { City::Madrid, Color::Blue },
            { City::Manila, Color::Red },
            { City::MexicoCity, Color::Yellow },
            { City::Miami, Color::Yellow },
            { City::Milan, Color::Blue },
            { City::Montreal, Color::Blue },
            { City::Moscow, Color::Black },
            { City::Mumbai, Color::Black },
            { City::NewYork, Color::Blue },
            { City::Osaka, Color::Red },
            { City::Paris, Color::Blue },
            { City::Riyadh, Color::Black },
            { City::SanFrancisco, Color::Blue },
            { City::Santiago, Color::Yellow },
            { City::SaoPaulo, Color::Yellow },
            { City::Seoul, Color::Red },
            { City::Shanghai, Color::Red },
            { City::StPetersburg, Color::Blue },
            { City::Sydney, Color::Red },
            { City::Taipei, Color::Red },
            { City::Tehran, Color::Black },
            { City::Tokyo, Color::Red },
            { City::Washington, Color::Blue }
    };
    //lets do unordered_map<City,color>

    const std::unordered_map<City,std::unordered_set<City>> neighbors {
            { City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo } },
            { City::Atlanta, {City::Chicago, City::Miami, City::Washington } },
            { City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi } },
            { City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong } },
            { City::Beijing, {City::Shanghai, City::Seoul } },
            { City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires } },
            { City::BuenosAires, {City::Bogota, City::SaoPaulo } },
            { City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh } },
            { City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta } },
            { City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal } },
            { City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata } },
            { City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg } },
            { City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila } },
            { City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei } },
            { City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow } },
            { City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney } },
            { City::Johannesburg, {City::Kinshasa, City::Khartoum } },
            { City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi } },
            { City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg } },
            { City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg } },
            { City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong } },
            { City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa } },
            { City::Lima, {City::MexicoCity, City::Bogota, City::Santiago } },
            { City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris } },
            { City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney } },
            { City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers } },
            { City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney } },
            { City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota } },
            { City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota } },
            { City::Milan, {City::Essen, City::Paris, City::Istanbul } },
            { City::Montreal, {City::Chicago, City::Washington, City::NewYork } },
            { City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran } },
            { City::Mumbai, {City::Karachi, City::Delhi, City::Chennai } },
            { City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid } },
            { City::Osaka, {City::Taipei, City::Tokyo } },
            { City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London } },
            { City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi } },
            { City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila } },
            { City::Santiago, {City::Lima } },
            { City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid } },
            { City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo } },
            { City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo } },
            { City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow } },
            { City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles } },
            { City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila } },
            { City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi } },
            { City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco } },
            { City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami } }
    };

}