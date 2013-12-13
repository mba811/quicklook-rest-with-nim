Debugging Quicklook plugins
===========================

See
http://stackoverflow.com/questions/16811547/debugging-quicklook-plugin-in-xcode-4-6.
Extract:

You can use brake points and NSLog function for debugging QL plugin. But first
you need to configure environment.

* Select your project on Project Navigator
* Then select QL plugin target
* Go to 'Build Phases' tab and add new phase 'Copy files'
* Select 'Absolute Path' on destination drop down menu and set
  ~/Library/QuickLook as subpath
* Open terminal and copy qlmanage to your project's root directory with command
  cp /usr/bin/qlmanage PROJECT_ROOT_DIR
* Then select menu Product -> Scheme -> Edit Scheme...
* Select 'Run' on schemes list
* On info tab select executable drop down menu, then 'Other...' and select
  qlmanage binary you have copied to project's root directory
* On arguments tab add row for 'Arguments Passed On Launch' and set value to -p
  FULL_PATH_TO_FILE_FOR_PREVIEW

After all steps you can run your project and debug your code.
