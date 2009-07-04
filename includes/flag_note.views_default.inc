<?php

// REMBER TO WRAP ALL WITH t() (ONE DAY :)

/**
 * Implementation of hook_views_default_views().
 */
function flag_note_views_default_views() {
  $views = array();

  foreach (flag_get_flags() as $flag) {
    $view = new view;
    $view->name = 'flag_note_flag_'. $flag->name; // MANUALLY
    $view->description = 'Flag notes for flag '. $flag->name; // MANUALLY
    $view->tag = '';
    $view->view_php = '';
    $view->base_table = 'node';
    $view->is_cacheable = FALSE;
    $view->api_version = 2;
    $view->disabled = TRUE; // MANUALLY
    $handler = $view->new_display('default', 'Defaults', 'default');
    $handler->override_option('relationships', array(
      'flag_content_rel' => array(
        'label' => 'flag',
        'required' => 0,
        'flag' => $flag->name, // MANUALLY
        'user_scope' => 'any',
        'id' => 'flag_content_rel',
        'table' => 'node',
        'field' => 'flag_content_rel',
        'relationship' => 'none',
      ),
      'flag_note_node_rel' => array(
        'label' => 'Flag note on node',
        'required' => 1,
        'id' => 'flag_note_node_rel',
        'table' => 'node',
        'field' => 'flag_note_node_rel',
        'relationship' => 'none',
      ),
      'flag_note_author_rel' => array(
        'label' => 'flag_note_author',
        'required' => 1,
        'id' => 'flag_note_author_rel',
        'table' => 'flag_note',
        'field' => 'flag_note_author_rel',
        'relationship' => 'flag_note_node_rel',
      ),
    ));
    $handler->override_option('fields', array(
      'title' => array(
        'label' => 'Title',
        'alter' => array(
          'alter_text' => 0,
          'text' => '',
          'make_link' => 0,
          'path' => '',
          'alt' => '',
          'prefix' => '',
          'suffix' => '',
          'help' => '',
          'trim' => 0,
          'max_length' => '',
          'word_boundary' => 1,
          'ellipsis' => 1,
          'strip_tags' => 0,
          'html' => 0,
        ),
        'link_to_node' => 1,
        'exclude' => 0,
        'id' => 'title',
        'table' => 'node',
        'field' => 'title',
        'relationship' => 'none',
      ),
      'note' => array(
        'id' => 'note',
        'table' => 'flag_note',
        'field' => 'note',
      ),
      'name' => array(
        'label' => 'Note author',
        'alter' => array(
          'alter_text' => 0,
          'text' => '',
          'make_link' => 0,
          'path' => '',
          'alt' => '',
          'prefix' => '',
          'suffix' => '',
          'help' => '',
          'trim' => 0,
          'max_length' => '',
          'word_boundary' => 1,
          'ellipsis' => 1,
          'strip_tags' => 0,
          'html' => 0,
        ),
        'link_to_user' => 1,
        'overwrite_anonymous' => 0,
        'anonymous_text' => '',
        'exclude' => 0,
        'id' => 'name',
        'table' => 'users',
        'field' => 'name',
        'relationship' => 'flag_note_author_rel',
      ),
      'timestamp' => array(
        'label' => 'Note created time',
        'alter' => array(
          'alter_text' => 0,
          'text' => '',
          'make_link' => 0,
          'path' => '',
          'alt' => '',
          'prefix' => '',
          'suffix' => '',
          'help' => '',
          'trim' => 0,
          'max_length' => '',
          'word_boundary' => 1,
          'ellipsis' => 1,
          'strip_tags' => 0,
          'html' => 0,
        ),
        'date_format' => 'small',
        'custom_date_format' => '',
        'exclude' => 0,
        'id' => 'timestamp',
        'table' => 'flag_note',
        'field' => 'timestamp',
        'relationship' => 'flag_note_node_rel',
      ),
      'delete_note' => array(
        'label' => 'Delete flag note',
        'alter' => array(
          'alter_text' => 0,
          'text' => '',
          'make_link' => 0,
          'path' => '',
          'alt' => '',
          'prefix' => '',
          'suffix' => '',
          'help' => '',
          'trim' => 0,
          'max_length' => '',
          'word_boundary' => 1,
          'ellipsis' => 1,
          'strip_tags' => 0,
          'html' => 0,
        ),
        'text' => '',
        'exclude' => 0,
        'id' => 'delete_note',
        'table' => 'flag_note',
        'field' => 'delete_note',
        'relationship' => 'flag_note_node_rel',
      ),
    ));
    $handler->override_option('sorts', array(
      'timestamp' => array(
        'order' => 'DESC',
        'granularity' => 'second',
        'id' => 'timestamp',
        'table' => 'flag_note',
        'field' => 'timestamp',
        'relationship' => 'flag_note_node_rel',
      ),
    ));
    $handler->override_option('access', array(
      'type' => 'perm',
      'perm' => 'administer flags',
    ));
    $handler->override_option('title', 'Flag notes for flag');
    $handler->override_option('items_per_page', 50);
    $handler->override_option('distinct', 1);
    $handler->override_option('style_plugin', 'table');
    $handler->override_option('style_options', array(
      'grouping' => '',
      'override' => 1,
      'sticky' => 0,
      'order' => 'asc',
      'columns' => array(
        'title' => 'title',
        'note' => 'note',
        'name' => 'name',
        'timestamp' => 'timestamp',
        'delete_note' => 'delete_note',
      ),
      'info' => array(
        'title' => array(
          'sortable' => 0,
          'separator' => '',
        ),
        'note' => array(
          'sortable' => 0,
          'separator' => '',
        ),
        'name' => array(
          'sortable' => 0,
          'separator' => '',
        ),
        'timestamp' => array(
          'sortable' => 0,
          'separator' => '',
        ),
        'delete_note' => array(
          'separator' => '',
        ),
      ),
      'default' => '-1',
    ));
    $handler = $view->new_display('page', 'Page', 'page_1');
    $handler->override_option('path', 'flagnote/view/flag_' . $flag->name); // MANUALLY
    $handler->override_option('menu', array(
      'type' => 'none',
      'title' => '',
      'description' => '',
      'weight' => 0,
      'name' => 'navigation',
    ));
    $handler->override_option('tab_options', array(
      'type' => 'none',
      'title' => '',
      'description' => '',
      'weight' => 0,
    ));

    // MANUALLY
    $views[$view->name] = $view;
  }

  return $views;
}
