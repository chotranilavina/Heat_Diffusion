h=0.02;
alpha=1.9e-5;
dt=((h^2)/(4*alpha))-1;
time=10000;
lent=ceil(time/dt);
lenx=1/h;
time=0:dt:10000;
T=zeros(lent,lenx,lenx);
x=0:h:1;
y=0:h:1;
for i=2:lenx-1
    for j=2:lenx-1
        if((x(i)-0.5)^2+(y(j)-0.5)^2<0.2)
            T(1,i,j)=40;
        else
            T(1,i,j)=20;
        end
    end
end
for t=2:lent-1
    for i=2:lenx-1
        for j=2:lenx-1
            T(t,i,j)=T(t-1,i,j)*(1-(4*alpha*dt)/(h^2)) + (alpha*dt/(h^2))*(T(t,i,j-1)+T(t,i-1,j)+ T(t,i+1,j) +T(t,i,j+1));
        end
    end
end
M=zeros(lenx+1,lenx+1);
for i=1:lenx
    for j=1:lenx
        M(i,j)=T(1,i,j);
    end
end
l=time(1)
surf(x,y,M);
