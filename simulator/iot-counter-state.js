/*global log*/
/*global updateState*/
/*global updateProperty*/
/*jslint node: true*/

"use strict";

// Default state
var state = {
	"timestamp": "2015-03-25T12:00:00Z", 
	"count": 6,
	"correlationId": "62c3bcb3-68a2-4fc5-9d07-0866916832dd"
};

// Default device properties
var properties = {
    "type": "Rebutton",
    "firmware": "1.0.0",
    "model": "iot-hand-tally-counter-01",
    "totalCount": 0,
    "batteryVoltage": 2.59,
    "initialState": false,
    "wifiPassPhase": "",
    "wifiSSID": ""
};

/**
 * Restore the global state using data from the previous iteration.
 *
 * @param previousState device state from the previous iteration
 * @param previousProperties device properties from the previous iteration
 */
function restoreSimulation(previousState, previousProperties) {
    // If the previous state is null, force a default state
    if (previousState) {
        state = previousState;
    } else {
        log("Using default state");
    }

    if (previousProperties) {
        properties = previousProperties;
    } else {
        log("Using default properties");
    }
}

function uuidv4() {
    return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function (c) {
        var r = Math.random() * 16 | 0, v = c == 'x' ? r : (r & 0x3 | 0x8);
        return v.toString(16);
    });
}

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

    // Restore the global state before generating the new telemetry, so that
    // the telemetry can apply changes using the previous function state.
    restoreSimulation(previousState, previousProperties);

    // update random count (1-10)
    state.count = Math.floor(Math.random() * 10) + 1;

    log("random count: " + state.count);

    // update total count
    properties.totalCount = previousProperties.totalCount + state.count;

    log("total count: " + properties.totalCount);

    // update timestamp now
    state.timestamp = context.currentTime;

    // update corellation id 
    state.correlationId = uuidv4();

    log("new correlationId" + state.correlationId);

    updateProperty(properties);

    updateState(state);
}