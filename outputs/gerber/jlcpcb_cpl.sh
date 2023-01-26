#!/bin/bash

cp m0116-bottom-pos.csv jlcpcb-cpl-bottom.csv
cp m0116-top-pos.csv jlcpcb-cpl-top.csv

perl -pi -e "s/Ref,Val,Package,PosX,PosY,Rot,Side/Designator,Mid X,Mid Y,Rotation,Layer/" jlcpcb-cpl*.csv
perl -pi -e 's/","[^"]*","[^"]*"/"/' jlcpcb-cpl*.csv


# manual placement fix
perl -pi -e 's/^"U3",(.*),180/"U3",\1,-90/' jlcpcb-cpl*.csv
perl -pi -e 's/^"U4",(.*),180/"U4",\1,-90/' jlcpcb-cpl*.csv
perl -pi -e 's/^"U5",(.*),90/"U5",\1,-90/' jlcpcb-cpl*.csv
perl -pi -e 's/^"Y1",(.*),0.000000/"Y1",\1,180.000000/' jlcpcb-cpl*.csv
perl -pi -e 's/^"Q4",(.*),-90/"Q4",\1,90/' jlcpcb-cpl*.csv

