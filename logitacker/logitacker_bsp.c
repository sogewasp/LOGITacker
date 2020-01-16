#include "logitacker.h"
#include "logitacker_bsp.h"
#include "nrf.h"
#include "bsp.h"

#define NRF_LOG_MODULE_NAME LOGITACKER_BSP
#include "nrf_log.h"
NRF_LOG_MODULE_REGISTER();


void logitacker_bsp_init(bsp_event_callback_t main_event_handler_bsp) {
    ret_code_t ret;

    /* Initializes the board support package to allow state indication and button reaction.
     * Default events are assigned to buttons. */
    ret = bsp_init(BSP_INIT_BUTTONS, main_event_handler_bsp);
    APP_ERROR_CHECK(ret);

    /* Assigning a specific (custom) event to a button. */
    bsp_event_to_button_action_assign(BTN_TRIGGER_ACTION, BSP_BUTTON_ACTION_RELEASE, BSP_USER_EVENT_RELEASE_0);
    bsp_event_to_button_action_assign(BTN_TRIGGER_ACTION, BSP_BUTTON_ACTION_LONG_PUSH, BSP_USER_EVENT_LONG_PRESS_0);

    /* Configure LEDs */
    bsp_board_init(BSP_INIT_LEDS);

}

