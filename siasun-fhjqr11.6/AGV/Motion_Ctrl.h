/*
 * Motion_Ctrl.h
 *
 *  Created on: 2019-9-25
 *      Author: siasunhebo
 */

#ifndef MOTION_CTRL_H_
#define MOTION_CTRL_H_

/*--------------------------------action mode define---------------------------------*/
#define ACTION_MODE_STOP        MOTIONSTATE_ONSTOPING
#define ACTION_MODE_GOAHEAD     MOTIONSTATE_GOSTRAIGHT
#define ACTION_MODE_GOBACK      MOTIONSTATE_GOBACKWARD
#define ACTION_MODE_TRUNLEFT    MOTIONSTATE_TRUNLEFT
#define ACTION_MODE_TRUNRIGHT   MOTIONSTATE_TRUNRIGHT


typedef enum
{
    MOTIONSTATE_ONSTOPING = 0,
    MOTIONSTATE_GOSTRAIGHT = 1,
    MOTIONSTATE_TRUNLEFT = 2,
    MOTIONSTATE_TRUNRIGHT = 3,
    MOTIONSTATE_ONLOADING = 4,
    MOTIONSTATE_GOBACKWARD = 5,
} motion_state_m;




void Movement_Control_Goahead();
void Movement_Control_Goback();
void Movement_Control_Left();
void Movement_Control_Right();



#endif /* MOTION_CTRL_H_ */
