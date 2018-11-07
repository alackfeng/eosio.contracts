/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>
#include <eosiolib/time.hpp>

#include <string>

namespace pecker {

  using eosio::contract;
  using eosio::time_point;
  using eosio::name;
  using eosio::print;
  using std::string;

  struct infos_onchain {
    /* type - 1: 'banner',  2 - 'notice', 3 - 'tunnel' */
    unsigned int  type;
    time_point    declaration_time;
    string        labels;
    string        title;
    string        abstract;
    string        link;
    string        sources;
    string        poster;
    string        logo;

    const void print() const {
      eosio::print(type, "\n", labels, "\n", title, "\n", abstract, "\n", link, "\n", sources, "\n", poster, "\n", logo, "\n");
    }

    EOSLIB_SERIALIZE(infos_onchain, (type)(declaration_time)(labels)(title)(abstract)(link)(sources)(poster)(logo));
  };

  class [[eosio::contract("pecker.infos")]] infos : public contract {
  
    public: 
      using contract::contract;

      [[eosio::action]]
      void issue3( name issuer, string info);

      [[eosio::action]]
      void issue2( name issuer, const std::vector<string>& infos );

      [[eosio::action]]
      void issue( name issuer, const infos_onchain& infos );

  };

} /// namespace pecker