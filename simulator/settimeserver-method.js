// Default state
// Default state
var state = {
	"timestamp": "2015-03-25T12:00:00Z", 
	"count": 6,
	"correlationId": "62c3bcb3-68a2-4fc5-9d07-0866916832dd"
};


/**
 * Entry point function called by the simulation engine.
 * Returns updated simulation state.
 * Device property updates must call updateProperties() to persist.
 *
 * @param context             The context contains current time, device model and id
 * @param previousState       The device state since the last iteration
 * @param previousProperties  The device properties since the last iteration
 */
function main(context, previousState, previousProperties) {

    // Use context if the simulation depends on
    // time or device details.
    // Execute some logic, updating 'state'

    updateState(state);
}