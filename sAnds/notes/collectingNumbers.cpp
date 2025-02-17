/*


aise sochte hai ki hmlog ek ek krke number given array se uthate hai or
apne imaginary array me bharte jate hai

starting me step = 1 rkhte hai
kuki minimum ek step hoga hi kuki ek jagah se utha kr dusre jagah
rkhna to agar array sorted hai tb bhi step = 1 hoga hi

to start krte hai step=1 se
=> ab 1 ko utha lie or rkh die apne nye array me
=> ab 2 ke paas jaatee hai
        agar 2 ko index 1 se jaida hai tb to hm isi current step me
        2 ko bhi nye array me rkh sakte hai

        pr agar 2 ka index 1 ke index se kam hai to nya step start 
        krna pdega

=> ab 3 ke paas jaate hai
       or agar 3 ka index 2 se jaida hai tb to sahi hai
       kuki 3 ko current step me hi hmlog naye array me rkh
       dete

       pr 3 ka index agar 2 se kam hai to iska mtlb nya step shuru krna
       pdega

To isi trah general logic bnate hai


Code 

int steps=1;
     for(int i=2;i<=n;i++){
        if(mp[i]<mp[i-1]){
            steps++;

        }else{
            continue;

        }
     }


        




*/