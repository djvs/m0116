#!/usr/bin/zsh
#
cp m0116.csv jlcpcb-bom.editing.csv

perl -pi -e "s/^[^;]*;\"LED.*//" jlcpcb-bom.editing.csv

perl -pi -e "s/^[^;]*;\"H[0-9].*//" jlcpcb-bom.editing.csv

perl -pi -e "s/^[^;]*;\"SW_.*//" jlcpcb-bom.editing.csv

perl -pi -e "s/^[^;]*;\"BUZ1.*//" jlcpcb-bom.editing.csv

sed -i '/^$/d' jlcpcb-bom.editing.csv

awk -i inplace -F';' '{print $5,$3,$2}' OFS=',' jlcpcb-bom.editing.csv

perl -pi -e 's/^("USBLC6-2SC6.*)/$1,"C7519"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("Q_NMOS_GSD 2N7002.*)/$1,"C8545"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("Q_PMOS_GSD AO3401A.*)/$1,"C700954"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("Ferrite_Bead.*)/$1,"C1015"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("8MHz.*)/$1,"C389817"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("2N3904.*)/$1,"C411758"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("MMBT3904.*)/$1,"C411758"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("STM32F411RETx.*)/$1,"C94355"/' jlcpcb-bom.editing.csv

perl -pi -e 's/^("D_Small.*)/$1,"C81598"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("D_Schottky_Small.*)/$1,"C81598"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("0.1uF.*)/$1,"C49678"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("330.*)/$1,"C17630"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("SW_Push.*)/$1,"C318884"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("1uF.*)/$1,"C28323"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("10uF.*)/$1,"C15850"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("Conn_01x04.*)/$1,"C160404"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("10k.*)/$1,"C17414"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("ATmega32U4.*)/$1,"C44854"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("16MHz.*)/$1,"C13738"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("22pF.*)/$1,"C1804"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("22".*)/$1,"C17561"/' jlcpcb-bom.editing.csv
perl -pi -e 's/^("XC6206P332MR".*)/$1,"C479053"/' jlcpcb-bom.editing.csv

perl -pi -e 's/^.Designation.*/Comment,Footprint,Designator,JLCPCB Part #（optional )/' jlcpcb-bom.editing.csv

cp -rvf jlcpcb-bom.editing.csv jlcpcb-bom.csv

rm jlcpcb-bom.editing.csv
