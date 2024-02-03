%Forward Kinematics Function for 6 frames of reference. 5Joints and an end
%effector

function[HM]=functionK(theta1, theta2, theta3, theta4, theta5, omega1,omega2, omega3, omega4, omega5,r1, r2, r3,r4,r5,d1,d2,d3,d4,d5)
%Calculate Forward Kinematix Homogeneous Matrix

matrix1 = [cos(theta1) -sin(theta1)*cos(omega1) sin(theta1)*sin(omega1) r1*cos(theta1);sin(theta1) cos(theta1)*cos(omega1) -cos(theta1)*sin(omega1) r1*sin(theta1); 0 sin(omega1) cos(omega1) d1; 0 0 0 1];
matrix2 = [cos(theta2) -sin(theta2)*cos(omega2) sin(theta2)*sin(omega2) r2*cos(theta2);sin(theta2) cos(theta2)*cos(omega2) -cos(theta2)*sin(omega2) r2*sin(theta2); 0 sin(omega2) cos(omega2) d2; 0 0 0 1];
matrix3 = [cos(theta3) -sin(theta3)*cos(omega3) sin(theta3)*sin(omega3) r3*cos(theta3);sin(theta3) cos(theta3)*cos(omega3) -cos(theta3)*sin(omega3) r3*sin(theta3); 0 sin(omega3) cos(omega3) d3; 0 0 0 1];
matrix4 = [cos(theta4) -sin(theta4)*cos(omega4) sin(theta4)*sin(omega4) r4*cos(theta4);sin(theta4) cos(theta4)*cos(omega4) -cos(theta4)*sin(omega4) r4*sin(theta4); 0 sin(omega4) cos(omega4) d4; 0 0 0 1];
matrix5 = [cos(theta5) -sin(theta5)*cos(omega5) sin(theta5)*sin(omega5) r5*cos(theta5);sin(theta5) cos(theta5)*cos(omega5) -cos(theta5)*sin(omega5) r5*sin(theta5); 0 sin(omega5) cos(omega5) d5; 0 0 0 1];

HM = matrix1*matrix2*matrix3*matrix4*matrix5;

end