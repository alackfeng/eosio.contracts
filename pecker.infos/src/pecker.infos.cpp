/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <pecker.infos/pecker.infos.hpp>

namespace pecker {

void infos::issue( name issuer, const info_onchain& info )
{
  print(issuer, "\n");
  // print(info);

  infos_table  _infos( _self, _self.value);

  _infos.emplace( _self, [&]( auto& _info ) {
    _info.id           = _infos.available_primary_key();
    _info.owner        = issuer;
    _info.declare      = now();
    _info.info         = info;
  });

}

void infos::revoke( name issuer, uint64_t id )
{

  print("revoke \n");
  require_auth( issuer ); 

  infos_table  _infos( _self, _self.value);

  auto itr = _infos.find(id);
  eosio_assert(itr != _infos.end(), "revoke info not found!!!");

  eosio_assert(itr->owner == issuer, "revoke not owner you !!!");

  // print(info->id);
  //delete
  _infos.erase(itr);

}


} /// namespace pecker

EOSIO_DISPATCH( pecker::infos, (issue)(revoke))