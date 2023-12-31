# Context Tutorials


## Example 1

   This example demonstrates how to access data in the XML file using the Context class

   as well as how to save the structured data into XML


### What to pay attention to in *test_context.py*

  The following functions:

  *  ```ctx = Context()```   creates an empty Context object

  * ```ctx = Context("ctx_example.xml")```  creates a Context object *ctx* that contains information parsed from
  the XML file *ctx_example.xml*

  * ```ctx.save_xml("ctx_1.xml")```  to save the data contained in the *ctx* object into a new XML file

  * ```ctx.get_path()```  to show the current node's name (path element)

  * ```ctx.set_path("new_path")``` to rename the current node

  * ```ctx.add("param1", param1)``` to add a parameter to the current node - as it's new branch, the tree may have many
  identically-names branches.

  * ```ctx.get("param2", "Milk")```  to retrieve value of the node's brach named "param2". If such branch does not exist
  the default value supplied ("Milk") will be returned. Note that the ```get``` function can do the type conversion, to 
  the default value type, so one can also do stuff like ```ctx.get("param1a", -1)``` expecting an integer
  


## Example 2 

   This example demonstrates how to access data in the XML file using the Context class

   The xml file is generated by the QE software and contains 100 MD steps for a Si_8 cluster

### What to pay attention to

  The following functions:

  * ```ctx.set_path_separator("/")```  set the path separator to be the "/" symbol, rather than the default "." 
  This is expecially important if the key names contain "." as their integral part. With this, we can have:
  ```
  <K_point.1>
     <Wfc.1>
     </Wfc.1>
  </K_point.1>
  ```
  parsed successfully

  * ```ctx1 = ctx.get_child("step", dctx)```   creates a new Context object *ctx1*  that represents one of the 
  branches of the original *ctx* object

  *  ```steps = ctx.get_children("step")```      get all the children of the current node such that they all
  have the "step" tag. Create an array of Context objects

  *  ```all1 = ctx.get_children_all()```  similar to *get_children*, but don't cares about the name of the tag to search.
  Will create an array of Context objects that represent all the node's branches

  * ```atoms[0].show_children()``` show all the keys of the corresponding Context object - these are its branch tag names.

  * ```atoms[i].get("", "")```   to retrieve the current node's data

  *  ```atoms[i].get("<xmlattr>/index", -1.0)```  to retrieve the node's branch data, if exist. Or return the default value given
