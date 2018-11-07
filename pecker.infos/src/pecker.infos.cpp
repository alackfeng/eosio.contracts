/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <pecker.infos/pecker.infos.hpp>

namespace pecker {

void infos::issue3( name issuer, string info)
{

  print(issuer);
}

void infos::issue2( name issuer, const std::vector<string>& infos )
{
  print(issuer, "\n");
}

void infos::issue( name issuer, const infos_onchain& infos )
{
  print(issuer, "\n");
  print(infos);
}


} /// namespace pecker

EOSIO_DISPATCH( pecker::infos, (issue)(issue2)(issue3))