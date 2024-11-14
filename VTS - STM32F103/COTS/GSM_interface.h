/**
 *
 * @file GSM_interface.h
 * @author Avelabs - Group A
 * @brief This file that implements the GSM driver in HAL
 * @version 1.00
 */

#ifndef GSM_INTERFACE_H_
#define GSM_INTERFACE_H_

void GSM_voidInit(void);
void GSM_voidSendToServer(u8 * Copy_pu8Data, u8 * Copy_pu8Lon, u8 * Copy_pu8Lat);
u8 GSM_voidGetAck(void);

#endif /* GSM_INTERFACE_H_ */
