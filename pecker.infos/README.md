pecker.infos
-----------

This pecker contract allows users to create and manage infos on
eosio based blockchains.



## 测试eosio两个新工程：eosio.cdt | eosio.contracts

#### 


`````bash

cleos ${MBP_URL} create key --to-console
Private key: 5JbuZx3MFvUY1FkYoWdR1o8b4TRCZwQJQzCvrT6JwVdQgLzscVo
Public key: EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv
cleos ${MBP_URL} create key --to-console
Private key: 5J4j8MJdhiHGmJ26CGTHvqMWYeYNMTEL6itTaxXFPAUpPfPm61L
Public key: EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH



cleosd get account pecker.infos
cleosd system newaccount --transfer eosio pecker.infos EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "10.001 EOS" --stake-cpu "10.001  EOS" --buy-ram "1.000 EOS" 
cleosd transfer eosio pecker.infos "10.0000 EOS"
cleosd system newaccount --transfer taurus peckersinfos EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "10.001 EOS" --stake-cpu "10.001  EOS" --buy-ram "1.000 EOS" 
cleosd transfer eosio peckersinfos "10.0000 EOS"


cleosd get code pecker.infos

cleosd get currency balance eosio.token pecker.infos
968.6940 EOS
cleosd get table eosio.token EOS stat
{
  "rows": [{
      "supply": "1000002000.0000 EOS",
      "max_supply": "10000000000.0000 EOS",
      "issuer": "eosio"
    }
  ],
  "more": false
}

cleosd set contract pecker.infos /Users/tokenfun/source/chick-peck/eosio.contracts/build/pecker.infos
executed transaction: e6a8963e74896dc1ea1f0796a26de3a5a8dd113b04e5a7f0ed0c81f391d39bbc  2840 bytes  4071 us
cleosd set contract peckersinfos /Users/tokenfun/source/chick-peck/eosio.contracts/build/pecker.infos
executed transaction: 0cbfcf2cb2c8036693d18f173c99b429ba5cc6131b4a1ac3ebbdd0f92be2a0e1  2840 bytes  756 us

cleosd get code pecker.infos
code hash: 38f8ff18e96307efd2ba113b9823d25a048de94de55f024cce132893c6768982
cleosd get code peckersinfos
code hash: 478c17718561b49a54d148657a675fca799f819b7315560ff73717940a28235e


cleosd push action pecker.infos issue3 '[ "taurus", "info tunnel" ]' -p taurus@active
cleosd push action pecker.infos issue2 '{"issuer": "taurus", "infos": ["a", "b", "c"] }' -p taurus@active
cleosd push action pecker.infos issue2 '["taurus", ["a", "b", "c"] ]' -p taurus@active
cleosd push action pecker.infos issue '["taurus", {"type": 3, "declaration_time": "2018-10-20T12:10:32", "labels": "EOS|DAPP", "title": "十年 最震惊比特币世界的10天1", "abstract": "比特币是一场悄然兴起的革命。比特币走过十年，是一项革命性技术的浓缩历史。如果按照时间顺序梳理比特币十年，发现震撼了比特币世界的10天发生在大多数人听说比特币大事件，同时也影响了比特币的未来发展。", "link": "https://zerohero.one/", "sources": "ZEROHERO Offcial", "poster": "", "logo": null} ]' -p taurus@active

cleosd get currency balance eosio.token pecker.infos



`````



