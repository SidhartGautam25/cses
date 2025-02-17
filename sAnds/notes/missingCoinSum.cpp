/*

lets divide our array into three part

arr[visited] a arr[remaining]

now let say sum[visited] is the prefix sum of the arr[visited]
and also assume sum[visited] is such a number that
you can make any number from 1 to sum[visited] from the elements
of the arr[visited]

now lets take a into action
so can we say that if we include a also,then

we can have sum from  ( 1 to sum[visited] ) union (a to a+sum[visited])

now can we say that 

if(a<sum[visited])
then we can say that 
    we have sum from 1 to a+sum[visited] as a is overlapping

    so our answer will be greater than a+sum[visited] in this case


    but if a>sum[visited] we can say our answer will be sum[visited]+1
    as there is a gap in sum we have

    now also we have to minimize our answer,hence we have to minimize 
    our sum[visited] hence we will sort the array in ascending order






now come to the problem we have given


*/