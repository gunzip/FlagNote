$Id$

Description
===========
Flag Note extends Flag Module to allow users to enter a note when they flag
a piece of content.

This is useful for example when you want to flag user as a friend/fan writing a hint
or when you want to flag nodes/comments for abuse providing a descriptive reason.

Moreover there's the possibility to keep old notes (even when the content gets unflagged),
building a flag history.

Installation
============
The only required modules are flag and views, install these first:

  http://drupal.org/project/flag
  http://drupal.org/project/views

If you want to enter notes through popups then install popups api:

  http://drupal.org/project/popups

Documentation
=============
To use it:

  * create a new flag or edit an old one (admin/build/flags/edit/[flag name])
  * select link type = 'Flag note form'
  * eventually choose 'Disable flag history' if you want to get rid of older flag notes

In the same administration form you can opt to keep old notes (flag history)
or delete them when unflagging. Once this settings are saved, a form (or a popup)
with a textfield will appear when users flag content.

Notes and their history are listed through views (adding a Flag Note relationship).
To list content associated notes you must either activate at least one between
the predefined views or create a new one.

Some default views are provided to show notes about nodes and users (as tabs)
or relative to a specific flag (as a separate page). These default views are disabled by default.
Check their settings (ie. access rights) and enable/clone them.

Go to admin/user/permissions to assign 'delete notes' permissions to users.
By default only the admin can delete flag notes.

'View notes' rights are implied by views access rights.

There's a new [flag-note] token when using this with flag_action and token modules active.

Todo
====
Someday, only if there'll be demand for these ones:

  * critical: fix views filters
  * decouple history and notes
  * store notes when unflagging

Extra:

  * reduce duplicates in default views (now it's done through sql DISTINCT) with a filter
    $this->query->add_where(flag_note_node.uid = flag_content_node.uid OR flag_content_node.uid IS NULL)

Credits
=======
pahariwalla @ http://drupal.org/user/70811
gunzip @ http://drupal.org/user/25151
