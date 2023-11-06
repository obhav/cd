#addressbook

name=-1
city=-1
code=-1
phn=-1
ch=0

while [ $ch -ne 7 ]
do
echo "\n*********Address Book**********\n1.create database\n2.view database\n3.insert a record\n4.delete a record\n5.search a record\n6.modify a record\n7.Exit\n"
echo "Enter your choice : "
read ch
case $ch in
1) echo "\nEnter the file name : " 
   read fname
   echo "\nEnter the number of records to be enter : "
   read n
   i=$n
   while [ $i -ne 0 ]
   do
   echo "Enter name : "
   read name
   echo "Enter city : "
   read city
   echo "Enter Zipcode : "
   read code
   echo "Enter contact number : "
   read phn
   
   echo "\n$name\t\t$city\t\t$code\t\t$phn"
    echo "\n$name\t\t$city\t\t$code\t\t$phn" >> $fname
   
   i=$((i-1))
   done
    echo "\nYour data is stored successfully in $fname"
   ;;
2) echo "\n*************************************************************************"
   echo "\n                          Address Book                                   "
   echo "\n*************************************************************************"
   echo "\nName\t\tCity\t\tZipcode\t\tcontact NO."
   cat $fname
   ;;
3) echo "Enter name : "
   read name
   echo "Enter city : "
   read city
   echo "Enter Zipcode : "
   read code
   echo "Enter contact number : "
   read phn
   
   echo "\n$name\t\t$city\t\t$code\t\t$phn"
    echo "\n$name\t\t$city\t\t$code\t\t$phn" >> $fname
    echo "Your data is stored successfully in $fname"
    n=$((n + 1))
    ;;
4) touch temp
  echo "Enter name of record you want to delete : "
  read del
  if grep -w "$del" $fname 
  then
  grep -w -v "$del" $fname >> temp
  rm $fname
  mv temp $fname
  else
  echo "\nRecord not found"
  fi
;;
5) touch temp
   echo "Enter the name of record yo want to search : "
   read sc
   if grep -w "$sc" $fname 
  then
  grep -w -v "$sc" $fname >> temp
   else 
 echo "\nRecord not found"
 fi
;;
6) touch temp
   echo "Enter the name of record yo want to Modify : "
   read m
   if grep -w "$m" $fname 
   then
   grep -w -v "$m" $fname >> temp
   echo "Enter name : "
   read name
   echo "Enter city : "
   read city
   echo "Enter Zipcode : "
   read code
   echo "Enter contact number : "
   read phn
   
    echo "\n$name\t\t$city\t\t$code\t\t$phn"
    echo "\n$name\t\t$city\t\t$code\t\t$phn" >> temp
    else
    echo "\nRecord not found"
   fi
   rm $fname
   mv temp $fname 
;;
7) echo "\nExited"
;;
*) echo "\nEnter a valid choice "
;;
esac
done