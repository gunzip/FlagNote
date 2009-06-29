<?php
// $Id$

/**
 * @file
 *
 * Provides Flag note data to Views.
 */

/**
 * Implementation of hook_views_data().
 */
function flag_note_views_data() {
  $data = array();
  $groupname = t('Flag note');
  $data['flag_note']['table']['group'] = $groupname;

// DO NOT UNCOMMENT - FLAG NOTES __MUST__ BE PROVIDED THROUGH RELATIONSHIPS ONLY !!!
//
//  $data['flag_note']['table']['base'] = array(
//    'field' => 'fnid',
//    'title' => t('Flag note'),
//    'help' => t("Notes associated with flags."),
//  );
//  $data['flag_note']['table']['join'] = array(
//    'flag_content' => array(
//      'left_field' => 'fcid',
//      'field' => 'fcid',
//    ),
//    'node' => array(
//      'left_field' => 'nid',
//      'field' => 'content_id',
//    ),
//    'users' => array(
//      'left_field' => 'uid',
//      'field' => 'content_id',
//    ),
//    'comments' => array(
//      'left_field' => 'cid',
//      'field' => 'content_id',
//    ),
//  );

  // field (text)
  $data['flag_note']['note'] = array(
    'title' => t('Note text'),
    'help' => t('Display the text of the flag note.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // field (timestamp)
  $data['flag_note']['timestamp'] = array(
    'title' => t('Note created time'),
    'help' => t('Display the time the note was written.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // relationship (author)
  $data['flag_note']['flag_note_author_rel'] = array(
    'group' => $groupname,
    'title' => t('Author'),
    'help' => t('Relate a note to its author.'),
    'relationship' => array(
      'label' => t('flag_note_author'),
      'base' => 'users',
      'base field' => 'uid',
      'relationship field' => 'uid',
    ),
  );

  // relationship (notes on nodes)
  $data['node']['flag_note_node_rel'] = array(
    'group' => $groupname,
    'title' => t('Notes on node'),
    'help' => t('All notes associated with a flagged node.'),
    'relationship' => array(
      'label' => t('Flag note on node'),
      'base' => 'flag_note',
      'base field' => 'content_id',
      'relationship field' => 'nid',
    ),
  );

  // relationship (notes on users)
  $data['users']['flag_note_user_rel'] = array(
    'group' => $groupname,
    'title' => t('Notes on user'),
    'help' => t('All notes associated with a flagged user.'),
    'relationship' => array(
      'label' => t('Flag note on user'),
      'base' => 'flag_note',
      'base field' => 'content_id',
      'relationship field' => 'uid',
    ),
  );

  // relationship (notes on comments)
  $data['comments']['flag_note_comments_rel'] = array(
    'group' => $groupname,
    'title' => t('Notes on comment'),
    'help' => t('All notes associated with a flagged comment.'),
    'relationship' => array(
      'label' => t('Flag note on comment'),
      'base' => 'flag_note',
      'base field' => 'content_id',
      'relationship field' => 'cid',
    ),
  );

  return $data;
}
