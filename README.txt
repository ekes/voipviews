VoIP Views
----------

Views handling for adding into voipscripts. 

@todo 
 * IVR forms js tidy up.
 * Tidy up theme section.
 * see other notes in code.
 * make some example views.
 * add other notes to follow...

Possible extensions?
 * Create scripts to read out exposed filters, and wait for input?

voipScriptStore - what?
 It's an arrayobject, that acts like the voipscript object (thus
making them more interchangable). It could have just been arrays, 
but then they look and act differently, and other control functions
can be encapsulated.
 The other alternative would be to have an actual voipscript object
in the $view. However as parts of the view are rendered before others 
not in order they would end up in a script, it would have stil required
the use of arrays to pass some of the commands around before putting
them in the voipscript object. The voipscriptstore is also better for
the live_preview (and can be stored as a string easily).
