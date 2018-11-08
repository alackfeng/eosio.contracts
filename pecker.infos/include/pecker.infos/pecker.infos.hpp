/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>
#include <eosiolib/time.hpp>
#include <eosiolib/ignore.hpp>
#include <eosiolib/multi_index.hpp>

#include <string>

namespace pecker {

  using eosio::contract;
  using eosio::time_point;
  using eosio::name;
  using eosio::print;
  using eosio::ignore;
  using eosio::indexed_by;
  using eosio::const_mem_fun;
  using std::string;

  struct info_onchain {
    /* type - 1: 'banner',  2 - 'notice', 3 - 'tunnel' */
    unsigned int  type;
    string        labels;
    string        title;
    string        abstract;
    string        link;
    string        source;
    string        poster;
    string        logo;

    const void print() const {
      eosio::print(type, "\n", labels, "\n", title, "\n", abstract, "\n", link, "\n", source, "\n", poster, "\n", logo, "\n");
    }

    info_onchain() 
      : type(0), title(""), abstract(""), link(""), source(""), poster(""), logo("")
    {}

    inline info_onchain& operator=(info_onchain info) {
      
      eosio::print(info);

      type         = info.type;
      labels       = info.labels;
      title        = info.labels;
      abstract     = info.abstract;
      link         = info.link;
      source      = info.source;
      return *this;
    }

    EOSLIB_SERIALIZE(info_onchain, (type)(labels)(title)(abstract)(link)(source)(poster)(logo));
  };

  struct [[eosio::table, eosio::contract("pecker.infos")]] infos_onchain
  {
    uint64_t        id;
    name            owner;
    // time_point      declare;
    uint64_t        declare; // unix time, in seconds
    info_onchain    info;

    uint64_t primary_key() const { return id; } 
    uint64_t get_owner() const { return owner.value; }
    uint64_t get_declare() const { return declare; }

    EOSLIB_SERIALIZE(infos_onchain, (id)(owner)(declare)(info));
  };

  typedef eosio::multi_index< "infos"_n, infos_onchain, 
    eosio::indexed_by<"declare"_n, const_mem_fun<infos_onchain, uint64_t, &infos_onchain::get_declare> >,
    eosio::indexed_by<"owner"_n, const_mem_fun<infos_onchain, uint64_t, &infos_onchain::get_owner> > 
  > infos_table;

  class [[eosio::contract("pecker.infos")]] infos : public contract {
  
    public: 
      using contract::contract;

      [[eosio::action]]
      void issue( name issuer, const info_onchain& infos );

      [[eosio::action]]
      void revoke( name issuer, uint64_t id );

  };

} /// namespace pecker