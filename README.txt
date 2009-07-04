====
TODO
====

* provide some default views to show related notes for

  - existing flags (done)
  - nodes
  - users
  - comments

  (title + note + note date + note author + edit link + delete link)

* reduce duplicates in default views (now it's done through sql DISTINCT) with a filter
  $this->query->add_where(flag_note_node.uid = flag_content_node.uid OR flag_content_node.uid IS NULL)

* write some help

One day, only if there'll be demand for these ones:

  * store notes on unflag
  * think about using cck nodes for notes
