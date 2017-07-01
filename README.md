# PathNormalization

This objective-C based program takes in a path an normalize it. It checks for '.' or '..' in the path and remove them leaving the path
having no double dashes '//'. A valid path should not have any dot or double dashes.

Two algorithms was implemented:
* removeDot1 first removes the dots. In the second pass, it checks for double dashes and removes one of them. 
Time complexity is O(n) even though 2 passes are required. Space complexity is O(n) because one additional string is required.

* removeDot2 does everything in one pass. It checks for './' or '../' patterns, remove them. If these patterns happen at the beginning
of the path, then one '/' is added back.
Time complexity is O(n) even though 1 pass is required. Space complexity is O(n) because one additional string is required.
